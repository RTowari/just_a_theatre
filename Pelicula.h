#ifndef PELICULA_H
#define PELICULA_H

#include "DtPelicula.h"
#include "Comentario.h"

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

    void agregarComentario(Comentario*);
};

#endif
