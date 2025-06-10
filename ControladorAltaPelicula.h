#ifndef CONTROLADORALTAPELICULA
#define CONTROLADORALTAPELICULA

#include <string>
#include "IControladorAltaPelicula.h"

using namespace std;

class ControladorAltaPelicula: public IControladorAltaPelicula{
    public:
        void altaPelicula(string titulo, string sinopsis, float PuntajePromedio, string urlFoto);
        
};



#endif