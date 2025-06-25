#include "Cine.h"
#include "Pelicula.h"
#include "DtDireccion.h"
#include "DtCine.h"


#include <map>
#include <list>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

Cine::Cine(){}
Cine::Cine(int id,DtDireccion dtDireccion){
        this->id=id;
        this->dtDireccion=dtDireccion;
        this->topeSalas=0;
}
int Cine::getId(){
        return this->id;
}
//no permito setear ID esto lo controla y autogenera el manejador de cines

DtDireccion Cine::getDireccion() const{
    return this->dtDireccion;
}
void Cine::setDireccion(DtDireccion dtDireccion){
    this->dtDireccion=dtDireccion;
}
Cine::~Cine(){}

void Cine::agregarSala(Sala* sala){
    this->salas[this->topeSalas]=sala;
    this->topeSalas++;
}
int Cine::getTopeSalas(){
    return this->topeSalas;
}


void Cine::agregarPelicula(Pelicula* pelicula) {

    string titulo = pelicula->getTitulo();

    // Sino existe, la pone en el cine
    peliculas[titulo] = pelicula;


}

void Cine::eliminarPeliculaCine(string titulo){
      peliculas.erase(titulo);

}

void Cine::eliminarPeliculaDeFunciones(string titulo){
    for(int i=0; i<topeSalas; i++){
        salas[i]->eliminarPeliFuncion(titulo);
    }
}



std::vector<Sala*> Cine::obtenerSalas() {
    return std::vector<Sala*>(salas, salas + topeSalas);
}

// cu altafuncion
DtCine Cine::getDt(){
    return DtCine(this->id, this->dtDireccion);
}
Sala* Cine::obtenerSalaPorId(int id) {
    for(int i=0; i < topeSalas; i++){
        if (salas[i]->getId()==id){
            return salas[i];
        }
    }
    return nullptr;
}

bool Cine::existePelicula(string titulo){
    for (map<string,Pelicula*>::iterator iterator=peliculas.begin(); iterator!=peliculas.end(); ++iterator){
        string tituloObtenido = iterator->second->getTitulo();
        if (tituloObtenido == titulo){
            return true;
        }
    }
    return false;
}

// cu altaReserva
// agregado para alta reserva
list<DtSala> Cine::obtenerSalasPorPelicula(string titulo){
    list<DtSala> salasConPeliculaBuscada;
    for (int i = 0; i < topeSalas; ++i) {
        Sala* sala = salas[i];

        DtSala dtSala = sala->obtenerSalaPorPelicula(titulo);
        salasConPeliculaBuscada.push_back(dtSala);

    }

    return salasConPeliculaBuscada;
}
list <DtSala> Cine::obtenerSalasPorPeliculaYFecha(string titulo){
    list<DtSala> salasConPeliculaBuscada;
    for (int i = 0; i < topeSalas; ++i) {
        Sala* sala = salas[i];

        DtSala dtSala = sala->obtenerSalaPorPeliculaYFecha(titulo);

        // si no consegui ninguna funcion, entonces no pusheo la sala
        if (!dtSala.getDtFunciones().empty()) {
            salasConPeliculaBuscada.push_back(dtSala);
        }


    }

    return salasConPeliculaBuscada;
}

