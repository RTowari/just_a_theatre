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

DtPelicula Pelicula::getDt() {
    return DtPelicula(this->titulo, this->sinopsis, this->puntajePromedio, this->poster);
}

vector<Comentario*> Pelicula::getComentarios(){
    return this->comentarios;
}

void Pelicula::agregarComentario(Comentario* comentario){
    comentarios.push_back(comentario);
}

void Pelicula::agregarPuntaje(Usuario* u, int puntos) {
    if (u == nullptr) {
        throw std::invalid_argument("ERROR: El usuario no puede ser nulo al registrar puntaje en la película.");
    }
    //Buscar si el usuario ya puntuó esta película.
    Puntaje* puntajeExistente = obtienePuntajeUsuario(u->getNickname());
    if (puntajeExistente != nullptr) {
        // Si ya existe un puntaje de este usuario, es una MODIFICACIÓN.
        puntajeExistente->setPuntaje(puntos); 
    } else {
        // Pelicula es dueña de este Puntaje, por eso hace 'new'.
        Puntaje* nuevoPuntaje = new Puntaje(puntos, u);   
        this->puntajes.push_back(nuevoPuntaje);
    }
}

vector<Puntaje*> Pelicula::getPuntajes(){
    return this->puntajes;
}

Puntaje* Pelicula::obtienePuntajeUsuario(string nickname)  { 

    for (Puntaje* p : this->puntajes) {
        if (p != nullptr && p->getUsuario()!= nullptr) {
            if (p->getUsuario()->getNickname() == nickname) {
                return p; // ¡Encontramos el puntaje
            }
        }
    }
    // Si el bucle termina y no encontramos ningún puntaje de un usuario con ese nickname, se devuelve nullptr
    return nullptr;
}