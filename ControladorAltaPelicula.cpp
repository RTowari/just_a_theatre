#include "ControladorAltaPelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"

bool ControladorAltaPelicula::existePelicula(string titulo){
    return ManejadorPelicula::getInstancia()->existePelicula(titulo);
}

void ControladorAltaPelicula::altaPelicula(string titulo, string sinopsis, float PuntajePromedio, string urlFoto){
    
    // creo una peli con los datos que me paso
    Pelicula* p = new Pelicula(titulo, sinopsis, PuntajePromedio, urlFoto);

    // Llamo a la instancia de manejador y luego le paso la pelicula para que lo agregue
    ManejadorPelicula::getInstancia()->agregarPelicula(p);
    
}