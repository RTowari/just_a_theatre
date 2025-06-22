#ifndef CONTROLADORVERCOMENTARIOSYPUNTAJESDEPELICULA
#define CONTROLADORVERCOMENTARIOSYPUNTAJESDEPELICULA

#include "IControladorVerComentariosyPuntajesdePelicula.h"
#include "DtPuntaje.h"
#include "DtInfoPelicula.h"
#include <vector>


class ControladorVerComentariosyPuntajesdePelicula : public IControladorVerComentariosyPuntajesdePelicula{

        vector<DtPelicula> listarPeliculas();
        DtInfoPelicula* obtenerInfoPelicula(string titulo);
   
};


#endif