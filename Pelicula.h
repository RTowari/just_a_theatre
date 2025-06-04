#ifndef PELICULA_H
#define PELICULA_H

#include <string>
using namespace std;

class Pelicula {
private:
    string titulo;
    string sinopsis;
    float puntajePromedio;
    string poster;

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
};

#endif
