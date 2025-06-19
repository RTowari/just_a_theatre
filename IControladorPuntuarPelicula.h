#ifndef ICONTROLADORPUNTUARPELICULA
#define ICONTROLADORPUNTUARPELICULA

#include <string>
#include <vector>

#include "DtPelicula.h"
#include "DtPuntaje.h"

using namespace std;

class IControladorPuntuarPelicula{

    public:
        virtual vector<DtPelicula> listarPeliculas()=0;
        virtual int obtienePuntajeUsuario(string)=0;
        virtual void puntuarPelicula(string, int)=0;
};


#endif