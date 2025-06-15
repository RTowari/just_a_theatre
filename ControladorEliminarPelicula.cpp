#include "ControladorEliminarPelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include "ManejadorCine.h"

void ControladorEliminarPelicula::eliminarPelicula(string titulo){

    ManejadorCine::getInstancia()->eliminarPeliculaDeCines(titulo);
    

    ManejadorPelicula::getInstancia()->eliminarPelicula(titulo);
}

void ControladorEliminarPelicula::listarPeliculas(){
    ManejadorPelicula::getInstancia()->verPeliculas();
}