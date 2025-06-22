#include "ControladorVerInformacionPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "Cine.h"

#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"

#include <string>

void ControladorVerInformacionPelicula::setTitulo(std::string titulo){
    this->titulo = titulo;
}

std::string ControladorVerInformacionPelicula::getTitulo(){
    return this->titulo;
}

void ControladorVerInformacionPelicula::setIdC(int IdC){
    this->IdC = IdC;
}
int ControladorVerInformacionPelicula::getIdC(){
    return this->IdC;
}

DtPelicula ControladorVerInformacionPelicula::elegirDtPelicula() {

    // Llamo al manejador para que me devuelva una pelicula dado un titulo
    Pelicula* pelicula = ManejadorPelicula::getInstancia()->buscarPelicula(this->getTitulo());

    // Convierto la pelicula en un DT
    DtPelicula dtPelicula = pelicula->getDt();

    return dtPelicula;
}

// Devuelve un set de cines segun una pelicula cuyo titulo paso en el nombre de la funcion
list<DtCine> ControladorVerInformacionPelicula::listarCines() {
    
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();

    // Me devuelven listas
    std::list<Cine*> cines = manejadorC->getCines();
   
    // busco todos los cines y por cada uno que contenga la pelicula que quiero, lo pongo en una lista
    list<DtCine> dtCines;
    for(Cine* cine : cines) {
        if(cine->existePelicula(this->getTitulo())){ // esto me devuelve un true si el cine tiene la pelicula.
            DtCine dtCine = cine->getDt();
            dtCines.push_back(dtCine);
        }
    }

    return dtCines;     
}

// dado el titulo que se seteo antes de la pelicula y la id del cine seteada, devuelvo funciones para ese cine y pelicula junto a toda la info
list<DtSala> ControladorVerInformacionPelicula::listarFuncionesDeCine(){
    // esto me devuelve el cine en el que voy a buscar las funciones con determinado id
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(this->getIdC());

    // le pido a mi cine las funciones que me interesan en una determinada fecha
    list<DtSala> dtSalas = cine->obtenerSalasPorPeliculaYFecha(this->titulo);

    return dtSalas;
}