#ifndef CONTROLADORELIMINARPELICULA
#define CONTROLADORELIMINARPELICULA

#include "Pelicula.h"
#include "IControladorEliminarPelicula.h"

class ControladorEliminarPelicula : public IControladorEliminarPelicula{

    public:
        vector<DtPelicula> listarPeliculas();
        void eliminarPelicula(string titulo);
};




#endif