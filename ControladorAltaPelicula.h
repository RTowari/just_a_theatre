#ifndef CONTROLADORALTAPELICULA
#define CONTROLADORALTAPELICULA

#include <string>
#include "IControladorAltaUsuario.h"

using namespace std;

class ControladorAltaPelicula:public IControladorAltaUsuario{
    public:
        virtual void altaPelicula(string titulo, string sinopsis, float PuntajePromedio, string urlFoto)=0;
};



#endif