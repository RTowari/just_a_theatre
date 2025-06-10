#include "ControladorAltaPelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"

void ControladorAltaPelicula::altaPelicula(string titulo, string sinopsis, float PuntajePromedio, string urlFoto){
    
    // creo un usuario con los datos que me paso
    Pelicula* p = new Pelicula(titulo, sinopsis, PuntajePromedio, urlFoto);

    // Llamo a la instancia de manejador y luego le paso el usuario para que lo agregue
    ManejadorPelicula::getInstancia()->agregarPelicula(p);


}