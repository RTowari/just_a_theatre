#include "Pelicula.h"

Pelicula::Pelicula() {
    this->titulo = "";
    this->sinopsis = "";
    this->puntajePromedio = 0.0;
    this->poster = "";
}

Pelicula::Pelicula(string titulo, string sinopsis, float puntajePromedio, string poster) {
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->poster = poster;
}

Pelicula::~Pelicula() {}

void Pelicula::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Pelicula::setSinopsis(string sinopsis) {
    this->sinopsis = sinopsis;
}

void Pelicula::setPuntajePromedio(float puntajePromedio) {
    this->puntajePromedio = puntajePromedio;
}

void Pelicula::setPoster(string poster) {
    this->poster = poster;
}

string Pelicula::getTitulo() {
    return this->titulo;
}

string Pelicula::getSinopsis() {
    return this->sinopsis;
}

float Pelicula::getPuntajePromedio() {
    return this->puntajePromedio;
}

string Pelicula::getPoster() {
    return this->poster;
}
