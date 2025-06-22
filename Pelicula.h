#ifndef PELICULA_H
#define PELICULA_H

#include "DtPelicula.h"
#include "Comentario.h"
#include "Puntaje.h"
#include "Usuario.h"
#include <vector>
#include <string>

using namespace std;

class Pelicula {
private:
    string titulo;
    string sinopsis;
    float puntajePromedio;
    string poster;
    vector<Comentario*> comentarios;
    vector<Puntaje*> puntajes;
    
public:
    Pelicula();
    Pelicula(string, string, float, string);
    ~Pelicula();

    void setTitulo(string);
    void setSinopsis(string);
    void setPuntajePromedio(float);
    void setPoster(string);

    string getTitulo();
    string getSinopsis();
    float getPuntajePromedio();
    string getPoster();

    DtPelicula getDt();
    vector<Comentario*> getComentarios();
    vector<Puntaje*> getPuntajes();
    Puntaje* obtienePuntajeUsuario(string);
    float CalculaPuntajePromedio();

    void agregarComentario(Comentario*);
    void agregarPuntaje(Usuario*, int);
};

#endif
