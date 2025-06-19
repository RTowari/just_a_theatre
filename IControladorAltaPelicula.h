#ifndef ICONTROLADORALTAPELICULA
#define ICONTROLADORALTAPELICULA

#include <string>
using namespace std;

class IControladorAltaPelicula{
    public:
        virtual bool existePelicula(string titulo)=0;
        virtual void altaPelicula(string titulo, string sinopsis, float PuntajePromedio, string urlFoto)=0;
};


#endif