#include "Funcion.h"
#include "DtFuncion.h"
#include "DtReserva.h"
#include "DtPago.h"
#include "Pago.h"

Funcion::Funcion(){}
Funcion::Funcion(int id, DtFecha f, DtHorario h){
    this->id = id;
    this->fecha = f;
    this->horario = h;
}
Funcion::~Funcion(){
        for (Reserva* reserva : reservas) {
        delete reserva; 
    }
}

void Funcion::setId(int id){
    this->id = id;
}

void Funcion::setFecha(DtFecha f){
    this->fecha = f;
}

void Funcion::setHorario(DtHorario h){
    this->horario = h;
}

int Funcion::getId(){
    return this->id;
}

DtFecha Funcion::getFecha(){
    return this->fecha;
}

DtHorario Funcion::getHorario(){
    return this->horario;
}

void Funcion::agregarReserva(Reserva* reserva) {
    reservas.push_back(reserva);
    this->topeReserva=topeReserva+1;
}

list<Reserva*> Funcion::getReservas() {
    return reservas;
}

Pelicula* Funcion::getPelicula(){       //para cu eliminarPelicula
    return this->pelicula;
}

void Funcion::eliminarPelicula(){       //para cu eliminarPelicula
    this->pelicula = NULL;
}

string Funcion::getPeliculaTitulo(){
    return this->pelicula->getTitulo();
}

void Funcion::agregarPelicula(Pelicula* pelicula){
    this->pelicula=pelicula;
}

// cu CrearReserva
bool Funcion::existePelicula(string titulo){
    if(pelicula == nullptr) { // no hay pelicuula en esta funcion
        return false;
    }
    if(titulo == this->pelicula->getTitulo()){
        return true;
    }
    return false;
}
DtFuncion Funcion::getDt(){
    DtFuncion dtFunc(id, fecha, horario);

    for (Reserva* res : reservas) {
        // Create DtPago* by polymorphic call
        DtPago* dtPago = res->getPago()->getDt();

        // Create DtReserva with id and DtPago*
        DtReserva dtRes(res->getIdReserva(), dtPago);

        // Add DtReserva to DtFuncion
        dtFunc.addReserva(dtRes);
    }

    return dtFunc; // copies the entire structure
}

int Funcion::getTopeReserva(){
    return this->topeReserva;
}