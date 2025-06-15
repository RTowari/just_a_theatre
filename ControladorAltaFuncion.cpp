#include "ControladorAltaFuncion.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "ManejadorPelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Pelicula.h"

#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"

#include <string>
#include <map>
#include <list>

using namespace std;

void ControladorAltaFuncion::setTi(string Ti){
    this->Ti=Ti;
}

string ControladorAltaFuncion::getTi(){
    return this->Ti;
}

void ControladorAltaFuncion::setIdC(int IdC) {
    this->IdC=IdC;
}
int ControladorAltaFuncion::getIdC(){
    return this->IdC;
}

void ControladorAltaFuncion::setIdS(int IdS) {
    this->IdS=IdS;
}
int ControladorAltaFuncion::getIdS(){
    return this->IdS;
}

void ControladorAltaFuncion::setDtFecha(DtFecha dtFecha){
    this->dtFecha=dtFecha;
}
DtFecha ControladorAltaFuncion::getDtFecha(){
    return this->dtFecha;
}

void ControladorAltaFuncion::setDtHorario(DtHorario dtHorario){
    this->dtHorario=dtHorario;
}
DtHorario ControladorAltaFuncion::getDtHorario(){
    return this->dtHorario;
}


list<DtCine> ControladorAltaFuncion::listarCines(){
    // Llamo al menejador de cine y lo asigno a una variable
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();

    // Le pido la lista de cines en su forma de clase comun
    list<Cine*> lstCines = manejadorC->getCines();

    // Ahora convierto cada cine en su forma Dt y lo pongo en una lista
    list<DtCine> lstDtCines;  // Lista para mis dt
    for (Cine* cine : lstCines) {
        if (cine) {  // Ensure pointer is valid
            DtCine dtCine(cine->getId(), cine->getDireccion());  // Assuming a DtCine constructor
            lstDtCines.push_back(dtCine);
        }
    }

    // le devuelvo la lista a mi front end
    return lstDtCines;
}

list<DtSala> ControladorAltaFuncion::listarSalasDeCine(){
    // llamo al manejador cine
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();

    // el manejador de cine me da una lista de sus salas, dada la Id que eligio el usuario
    int IdC = this->getIdC();
    vector<Sala*> salas = manejadorC->obtenerSalasDeCine(IdC);

    list<DtSala> lstDtSalas;
    for(Sala* sala : salas) {
        DtSala dtSala = sala->getDt();
        lstDtSalas.push_back(dtSala);
    }

    return lstDtSalas;
}

// dado el id del cine, de la sala, y de la pelicula que el usuario ingreso en el front, agrego Funcion en esta funcion
void ControladorAltaFuncion::agregarFuncionASala(){
    
    // primero pido el cine
    // llamo al manejador cine
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();

    int IdC = this->getIdC(); // esta es la id que el usuario seteo en el front
    Cine* cineElegido = manejadorC->buscarCine(IdC); // esto me devuelve el cine que el usuario eligio

    // esta es la sala que el usuario eligio
    int IdS = this->getIdS();
    Sala* salaElegida = cineElegido->obtenerSalaPorId(IdS);

    // le pido al manejador funcion una Id que no exista en su sistema
    ManejadorFuncion* manejadorF = ManejadorFuncion::getInstancia();
    int idParaSala = manejadorF->generarNuevoId();

    // ahora puedo crear mi funcion, ya que tengo el id que necesito
    Funcion* nuevaFuncion = new Funcion(idParaSala, DtFecha(this->dtFecha), DtHorario(this->dtHorario));
    
    // agrego mi funcion al manejador
    manejadorF->agregarFuncion(nuevaFuncion);

    // ahora tengo que agregar la pelicula a mi funcion, asi que le pido la pelicula al menejador pelicula
    // el titulo que uso para buscar la pelicula se lo pedi al usuario y esta almacenado en mi controlador
    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();
    Pelicula* pelicula = manejadorP->buscarPelicula(this->getTi());

    // ahora que tengo mi pelicula por referencia, la pongo en la funcion
    nuevaFuncion->agregarPelicula(pelicula);

}

