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
Cine::~Cine(){
    for(int i = 0;i<this->topeSalas;i++){
        delete this->salas[i];
        this->salas[i] = nullptr ;
    }
}

void Cine::agregarSala(Sala* sala){
    this->salas[this->topeSalas]=sala;
    this->topeSalas++;
}
int Cine::getTopeSalas(){
    return this->topeSalas;
}
const Sala** Cine::obtenerSalas() const{
    Sala** salas = new Sala*[this->topeSalas];
    for(int i=0;i<this->topeSalas;i++)
        salas[i]=this->salas[i];
    return (const Sala**)this->salas;
}

void Cine::agregarPelicula(Pelicula* pelicula) {

    string titulo = pelicula->getTitulo();

    try {
        // Check por si la pelicula ya existe
        if (peliculas.find(titulo) != peliculas.end()) {
            throw std::runtime_error("Error: La pelicula '" + titulo + "' ya existe en el cine.");
        }

        // Sino existe, la pone en el cine
        peliculas[titulo] = pelicula;

    } catch (const std::runtime_error& e) {
        cout << e.what() << endl; // Print error message to console
    }
}

void Cine::eliminarPeliculaCine(string titulo){
    try{
      peliculas.erase(titulo);
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl; // Print error message to console
    }
}

void Cine::eliminarPeliculaDeFunciones(string titulo){
    for(int i=0; i<topeSalas; i++){
        salas[i]->eliminarPeliFuncion(titulo);
    }
}

void Cine::mostrarInformacion() const {
    cout << "\n--- Informacion del Cine ---" << endl;
    cout << "ID: " << id << endl;
    cout << "Direccion: Calle " << dtDireccion.getCalle() << ", Numero " << dtDireccion.getNumero() << endl;
    cout << "Cantidad de Salas: " << topeSalas << endl;

    if (topeSalas > 0) {
        cout << "  Salas:" << endl;
        // obtenerSalas() devuelve Sala**, que es un puntero al array de punteros a Salas.
        const Sala** salasArray = obtenerSalas();
        for (int i = 0; i < topeSalas; ++i) {
            if (salasArray[i] != nullptr) { // Verificación de seguridad
                cout << "    - Sala ID: " << salasArray[i]->getId()
                          << ", Capacidad: " << salasArray[i]->getCapacidad() << endl;
            }
        }
    } else {
        cout << "  (No hay salas registradas para este cine)" << endl;
    }
    cout << "----------------------------" << endl;
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