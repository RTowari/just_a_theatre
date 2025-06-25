#include "Cine.h"
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
}

ManejadorCine* ManejadorCine::getInstancia(){
    if(instancia == NULL)
        instancia = new ManejadorCine();
    return instancia;
}

int ManejadorCine::getSiguienteIdCine(){
    return ++this -> ultimoIdCine;
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

void ManejadorCine::darDeAltaCine(Cine* cine){
    // Verificar si el Cine con el ID proporcionado ya existe en la colección del manejador.
    map<int,Cine*>::iterator it = this->cines.find(cine->getId());
    
    if (it != this->cines.end()) {
        throw std::runtime_error("[ERROR CATASTROFICO] Se agrego un cine con una id que ya existe");
    }  
    
    //  Añadir el objeto Cine a la colección interna del manejador.
    cines.insert(std::pair<int,Cine*>(cine->getId(), cine)); 
    
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
        throw std::runtime_error("[ERROR CATASTROFICO] Se intento eliminar un cine con una Id que no existe");;
    }
}

void ManejadorCine::eliminarPeliculaDeCines(string titulo){
    for (map<int,Cine*>::iterator iterator=cines.begin(); iterator!=cines.end(); ++iterator){
        iterator->second->eliminarPeliculaCine(titulo);
        iterator->second->eliminarPeliculaDeFunciones(titulo);
    }
}

bool ManejadorCine::existePelicula(string titulo){
    for (map<int,Cine*>::iterator iterator=cines.begin(); iterator!=cines.end(); ++iterator){
        bool peliculaEnCine = iterator->second->existePelicula(titulo);
        if(peliculaEnCine == true){
            return true;
        }
    }
    return false;
}

ManejadorCine::~ManejadorCine(){}
