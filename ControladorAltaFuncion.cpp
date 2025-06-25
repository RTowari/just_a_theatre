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
#include "DtFuncion.h"

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
        if (cine) {  
            DtCine dtCine(cine->getId(), cine->getDireccion());  
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
    vector<Sala*> salas = manejadorC->buscarCine(IdC)->obtenerSalas();
        
    // ahora pongo dt funciones adentro de dt salas
    list<DtSala> lstDtSalas;
    for(Sala* sala : salas) {
        // a cada sala le pido sus funciones
        std::map<int, Funcion*> funciones = sala->obtenerFunciones();
        
        // convierto la sala en un dt que no tiene la coleccion de funciones
        DtSala dtSala = sala->getDt();

        // por cada funcion, agarro su dt y lo pusheo en el dt sala dt pusheo las funciones en formato dt
        for(map<int, Funcion*>::iterator it = funciones.begin(); it != funciones.end(); ++it){
            Funcion* funcion = it->second;


            DtFuncion dtFuncion = funcion->getDt();
            dtSala.agregarDtFuncion(dtFuncion);
        }

        lstDtSalas.push_back(dtSala);
    }

    return lstDtSalas;
}

// dado el id del cine, de la sala, y de la pelicula que el usuario ingreso en el front, agrego Funcion en esta funcion
void ControladorAltaFuncion::agregarFuncionASala(){
    
    // llamo manejadores
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();
    ManejadorFuncion* manejadorF = ManejadorFuncion::getInstancia();
    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();

    Cine* cineElegido = manejadorC->buscarCine(this->getIdC()); // esta es la id que el usuario seteo en el front

    // esta es la sala que el usuario eligio
    Sala* salaElegida = cineElegido->obtenerSalaPorId(this->getIdS());


    // le pido al manejador funcion una Id que no exista en su sistema
    int idParaSala = manejadorF->generarNuevoId();

    // ahora puedo crear mi funcion, ya que tengo el id que necesito
    Funcion* nuevaFuncion = new Funcion(idParaSala, DtFecha(this->dtFecha), DtHorario(this->dtHorario));
    
    // agrego mi funcion al manejador y a la sala

    manejadorF->agregarFuncion(nuevaFuncion);
    salaElegida->agregarFuncion(nuevaFuncion);
    

    // ahora tengo que agregar la pelicula a mi funcion, asi que le pido la pelicula al menejador pelicula
    // el titulo que usé para buscar la pelicula se lo pedi al usuario y esta almacenado en mi controlador
    Pelicula* pelicula = manejadorP->buscarPelicula(this->getTi());
    
    // ahora que tengo mi pelicula por referencia, la pongo en la funcion y en el cine
    nuevaFuncion->agregarPelicula(pelicula);
    // antes de agregar la pelicula al cine me aseguro de que no exista
    if(!cineElegido->existePelicula(this->getTi())){
        cineElegido->agregarPelicula(pelicula);
    }




}

