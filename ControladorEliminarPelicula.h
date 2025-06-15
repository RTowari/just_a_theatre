#ifndef CONTROLADORELIMINARPELICULA
#define CONTROLADORELIMINARPELICULA

#include "Pelicula.h"
#include "IControladorEliminarPelicula.h"

class ControladorEliminarPelicula : public IControladorEliminarPelicula{

    public:
        void listarPeliculas();
        void eliminarPelicula(string titulo);
};




#endif