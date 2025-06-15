#include "Cine.h"
#include "Sala.h"
#include <list>
#include <map>   
#include <string>
#include <vector> 
#include <stdexcept>
#include <iostream> 
#include "ManejadorCine.h"

using namespace std;

ManejadorCine* ManejadorCine::instancia = NULL;

ManejadorCine::ManejadorCine(){
     this->ultimoIdCine=0;
     this->ultimoIdSala=0;
}

ManejadorCine* ManejadorCine::getInstancia(){
    if(instancia == NULL)
        instancia = new ManejadorCine();
    return instancia;
}

int ManejadorCine::getSiguienteIdCine(){
    return ++this -> ultimoIdCine;
}

int ManejadorCine::generarNuevoIdSala() { 
    return ++this -> ultimoIdSala;
}

list<Cine*> ManejadorCine::getCines(){
    list<Cine*> lstCines;
    for (map<int,Cine*>::iterator iterator=this->cines.begin(); iterator!=cines.end(); ++iterator)
        lstCines.push_back(iterator->second);
    return lstCines;
}

Cine* ManejadorCine::buscarCine(int id){
    map<int,Cine*>::iterator it = this->cines.find(id);
    return it->second;
}

void ManejadorCine::darDeAltaCine(Cine* cine, const vector<int>& capacidadesSalas){
    // Verificar si el Cine con el ID proporcionado ya existe en la colección del manejador.
    map<int,Cine*>::iterator it = this->cines.find(cine->getId());
    if (it != this->cines.end()) {
        throw std::invalid_argument("Error en darDeAltaCine: El Cine con ID " + std::to_string(cine->getId()) + " ya existe en el sistema.");
    }  
    //  Añadir el objeto Cine a la colección interna del manejador.
     cines.insert(std::pair<int,Cine*>(cine->getId(), cine)); 
    //  Iterar sobre las capacidades proporcionadas y crear las Salas correspondientes.
    for (int capacidad : capacidadesSalas) {
        int nuevaIdSala = generarNuevoIdSala();
        //    La Sala es construida con su ID y la capacidad.
        Sala* nuevaSala = new Sala(nuevaIdSala, capacidad);
        //    El método agregarSala de la clase Cine se encargará de añadirla a su array interno.
        cine->agregarSala(nuevaSala);
    }
}

bool ManejadorCine::existeCine(int id){
    map<int,Cine*>::iterator it = this->cines.find(id);
    return (it != this->cines.end());
}

void ManejadorCine::eliminarCine(int id){
    map<int,Cine*>::iterator it = this->cines.find(id);
    if (it != this->cines.end()) {
        // el destructor de Cine se encarga de liberar las Salas.
        delete it->second; // liberar la memoria del objeto Cine
        cines.erase(it); // eliminar la entrada del mapa
    } else {
        throw invalid_argument("Error al eliminar cine: El cine con ID " + to_string(id) + " no existe.");
    }
}

void ManejadorCine::eliminarPeliculaDeCines(string titulo){
    for (map<int,Cine*>::iterator iterator=cines.begin(); iterator!=cines.end(); ++iterator){
        iterator->second->eliminarPeliculaCine(titulo);
        iterator->second->eliminarPeliculaDeFunciones(titulo);}
}

std::vector<Sala*> ManejadorCine::obtenerSalasDeCine(int id) {
    std::map<int, Cine*>::iterator it = this->cines.find(id);
    if (it != this->cines.end()) {
        return it->second->obtenerSalas();
    }
    return {};
}

ManejadorCine::~ManejadorCine(){}
