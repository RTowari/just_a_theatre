#ifndef CONTROLADORPUNTUARPELICULA
#define CONTROLADORPUNTUARPELICULA

#include "IControladorPuntuarPelicula.h"
#include "DtPuntaje.h"


class ControladorPuntuarPelicula : public IControladorPuntuarPelicula{

    public:
        vector<DtPelicula> listarPeliculas();
        int obtienePuntajeUsuario(string);
        void puntuarPelicula(string, int);
};


#endif