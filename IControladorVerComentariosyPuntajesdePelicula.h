#ifndef ICONTROLADORVERCOMENTARIOSYPUNTAJESDEPELICULA
#define ICONTROLADORVERCOMENTARIOSYPUNTAJESDEPELICULA

#include <string>
#include <vector>
#include "DtPelicula.h"
#include "DtInfoPelicula.h"

class IControladorVerComentariosyPuntajesdePelicula{
    public:
        virtual vector<DtPelicula> listarPeliculas() = 0;
        virtual DtInfoPelicula* obtenerInfoPelicula(string titulo) = 0;
};   

#endif