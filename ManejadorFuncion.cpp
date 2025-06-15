#include "Funcion.h"
#include "ManejadorFuncion.h"
#include <list>
#include <iostream>

using namespace std;

ManejadorFuncion* ManejadorFuncion::instancia = NULL;

ManejadorFuncion::ManejadorFuncion(){}

ManejadorFuncion* ManejadorFuncion::getInstancia(){
    if(instancia == NULL)
        instancia = new ManejadorFuncion();
    return instancia;
}

list<Funcion*> ManejadorFuncion::getFunciones(){
    list<Funcion*> lstFunciones;
    for (map<int, Funcion*>::iterator it=this->funciones.begin(); it!=funciones.end(); ++it)
        lstFunciones.push_back(it->second);
    return lstFunciones;
}

Funcion* ManejadorFuncion::buscarFuncion(int id){
    map<int, Funcion*>::iterator it = this->funciones.find(id);
    return it->second;
}

void ManejadorFuncion::agregarFuncion(Funcion* funcion) {
    funciones.insert(std::pair<int, Funcion*>(funcion->getId(), funcion));
}

bool ManejadorFuncion::existeFuncion(int id){
    map<int, Funcion*>::iterator it = this->funciones.find(id);
    return (it != this->funciones.end());
}

void ManejadorFuncion::eliminarFuncion(int id){
    map<int, Funcion*>::iterator it = this->funciones.find(id);
    this->funciones.erase(it);
}

void ManejadorFuncion::verFunciones(){
    for(map<int, Funcion*>::iterator it = this->funciones.begin(); it!=funciones.end(); ++it){
        cout << it->first << "\n" << endl;
    }
}

int ManejadorFuncion::generarNuevoId(){
    if(funciones.empty()){
        return 1; // esto me retorna una id de 1, que seria la primera si nunca agregue una funcion
    }

    // cuenta las id y retorna la mas grande sin importar el orden
    map<int, Funcion*>::iterator maxIdIt = funciones.begin();
    for (map<int, Funcion*>::iterator it = funciones.begin(); it != funciones.end(); ++it) {
        if (it->first > maxIdIt->first) {
            maxIdIt = it;
        }
    }

    return maxIdIt->first + 1;
}

ManejadorFuncion::~ManejadorFuncion(){}



