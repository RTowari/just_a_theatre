#include "ControladorPuntuarPelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include "Sesion.h"
#include <iostream>

vector<DtPelicula> ControladorPuntuarPelicula::listarPeliculas(){
    
    vector<DtPelicula> DtPeliculas;
    list<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();

    for (auto it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPeliculas.push_back((*it)->getDt());
    }

    return DtPeliculas;
}

int ControladorPuntuarPelicula:: obtienePuntajeUsuario(string titulo){
    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    if (p == nullptr) {
        throw std::invalid_argument("ERROR: Pelicula '" + titulo + "' no encontrada para consultar puntaje.");
    }
    Usuario* u = Sesion::getInstancia()->getUsuario();
    Puntaje* puntaje = p->obtienePuntajeUsuario(u->getNickname());
    if (puntaje != nullptr) {
        return puntaje->getPuntaje(); 
    }
    else {
        return -1;
    }
}

void ControladorPuntuarPelicula:: puntuarPelicula(string titulo, int nuevoPuntaje){
    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    Usuario* u = Sesion::getInstancia()->getUsuario();
        p->agregarPuntaje(u, nuevoPuntaje);
}

