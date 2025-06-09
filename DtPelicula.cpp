#include "DtPelicula.h"

DtPelicula::DtPelicula(){}
DtPelicula::DtPelicula(string titulo, string sinopsis, float puntajePromedio, string poster) {
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->poster = poster;
};

string DtPelicula::getTitulo() {
    return this->titulo;
}

string DtPelicula::getSinopsis() {
    return this->sinopsis;
}

float DtPelicula::getPuntajePromedio() {
    return this->puntajePromedio;
}

string DtPelicula::getPoster() {
    return this->poster;
}


DtPelicula::~DtPelicula() {}