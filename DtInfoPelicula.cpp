#include "DtInfoPelicula.h"

DtInfoPelicula::DtInfoPelicula(DtPelicula* dtPelicula, int cantUsuarios, vector<DtComentario> comentarios, vector<DtPuntaje> puntajes) {
    this ->infoPelicula = dtPelicula;
    this ->cantidadUsuariosPuntuaron = cantUsuarios;
    this -> comentarios = comentarios;
    this -> puntajes = puntajes;
}
  

// Implementación del destructor
DtInfoPelicula::~DtInfoPelicula() {
    delete infoPelicula; 
}

// Implementaciones de los getters
DtPelicula* DtInfoPelicula::getInfoBasica() {
    return infoPelicula;
}

int DtInfoPelicula::getCantidadUsuariosPuntuaron() {
    return cantidadUsuariosPuntuaron;
}

vector<DtComentario>& DtInfoPelicula::getComentarios() {
    return comentarios;
}

vector<DtPuntaje>& DtInfoPelicula::getPuntajes() {
    return puntajes;
}