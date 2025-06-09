#include "ManejadorPelicula.h"
#include "ControladorCrearReserva.h"
#include "DtPelicula.h"
#include "DtCine.h"

#include <list>
#include <string>
#include <vector>
#include <algorithm>

std::list<std::string> ControladorCrearReserva::listarPeliculas() {

    // Llamo al manejador y lo asigno a una variable
    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();

    // El manejador me devuelve una lista de pelicuulas
    std::list<Pelicula*> peliculas = manejadorP->getPeliculas();

    // Creo una lista de strings para almacenar los títulos
    std::list<std::string> titulos;

    // Itero sobre la lista de películas y extraigo los títulos
    for (Pelicula* pelicula : peliculas) {
        if (pelicula) {  // Asegurarse de que no sea nullptr
            titulos.push_back(pelicula->getTitulo()); 
        }
    }

    return titulos;

}

DtPelicula ControladorCrearReserva::elegirDtPelicula(string titulo) {

    // Llamo al manejador y lo asigno a una variable
    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();

    // El manejador me devuelve una lista de pelicuulas
    std::list<Pelicula*> peliculas = manejadorP->getPeliculas();

    // busco la pelicula que quiero en la lista
    Pelicula* p = manejadorP->buscarPelicula(titulo);

    // Convierto la pelicula en un DT
    DtPelicula DtP = p->getDt();



    return DtP;
}

// Devuelve un set de cines segun una pelicula cuyo titulo paso en el nombre de la funcion
/*std::vector<DtCine> ControladorCrearReserva::listarCines(string titulo) {
    // Llamo al manejador y lo asigno a una variable
    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();

    // El manejador me devuelve una lista de pelicuulas
    std::list<Pelicula*> peliculas = manejadorP->getPeliculas();

    // busco la pelicula que quiero en la lista (sé que existe porque el usuario la eligio antes)
    Pelicula* p = manejadorP->buscarPelicula(titulo);

}*/

