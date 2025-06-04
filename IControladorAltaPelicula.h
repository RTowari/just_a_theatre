#ifndef ICONTROLADORALTAPELICULA
#define ICONTROLADORALTAPELICULA

#include <string>
using namespace std;

class IControladorAltaPelicula{
    public:
        virtual void altaPelicula(string titulo, string sinopsis, float PuntajePromedio, string urlFoto)=0;
};


#endif