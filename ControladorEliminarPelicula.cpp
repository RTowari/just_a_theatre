#include "ControladorEliminarPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "Pelicula.h"
#include "ManejadorCine.h"

#include <iostream>

void ControladorEliminarPelicula::eliminarPelicula(string titulo){

    // borra los pointers a pelicula de CINE y los pointers de SALA a funcion
    ManejadorCine::getInstancia()->eliminarPeliculaDeCines(titulo);

    // con esto elimino todas las FUNCION(el objeto en si) que tengan una pelicula de un terminado titulo
    ManejadorFuncion::getInstancia()->eliminarFuncionPorTitulo(titulo);
    
    // aqui borro la pelicula directamente
    ManejadorPelicula::getInstancia()->eliminarPelicula(titulo);
}

vector<DtPelicula> ControladorEliminarPelicula::listarPeliculas(){
    vector<DtPelicula> DtPeliculas;
    list<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();

    for (auto it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPeliculas.push_back((*it)->getDt());
    }

    return DtPeliculas;
}