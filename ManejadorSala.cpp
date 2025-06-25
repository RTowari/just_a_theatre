#include "Sala.h"
#include <list>
#include "ManejadorSala.h"

using namespace std;

ManejadorSala* ManejadorSala::instancia = NULL;

ManejadorSala::ManejadorSala(){}

ManejadorSala* ManejadorSala::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorSala();
    return instancia;
}

list<Sala*> ManejadorSala::getSala(){
    return this->salas;
}

Sala* ManejadorSala::buscarSalas(int id){
    for (list<Sala*>::iterator it = this->salas.begin(); it != this->salas.end(); ++it) {
        if ((*it)->getId() == id) {
            return *it;
        }
    }
    return NULL;
}

void ManejadorSala::agregarSala(Sala* sala){
    this->salas.push_back(sala);
    topeSalas++;
}

bool ManejadorSala::existeSala(int id){ 
    for (list<Sala*>::iterator it = this->salas.begin(); it != this->salas.end(); ++it) {
        if ((*it)->getId() == id) {
            return true;
        }
    }
    return false;
}

void ManejadorSala::eliminarSala(int id){
    for (list<Sala*>::iterator it = this->salas.begin(); it != this->salas.end(); ++it) {
        if ((*it)->getId() == id) {
            this->salas.erase(it);
            break;
        }
    }
}

int ManejadorSala::getTopeSalas() {
    return this->topeSalas;
}

ManejadorSala::~ManejadorSala(){}
