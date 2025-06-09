#ifndef DTPELICULA_H
#define DTPELICULA_H

#include <string>

using namespace std;

class DtPelicula {
    private:
        string titulo;
        string sinopsis;
        float puntajePromedio;
        string poster;
    public:
        DtPelicula();
        DtPelicula(string, string, float, string);

        
        string getTitulo();
        string getSinopsis();
        float getPuntajePromedio();
        string getPoster();

        ~DtPelicula();
};

#endif