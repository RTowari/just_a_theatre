#ifndef CONTROLADORELIMINARPELICULA
#define CONTROLADORELIMINARPELICULA

#include "Pelicula.h"
#include "IControladorEliminarPelicula.h"

class ControladorEliminarPelicula : public IControladorEliminarPelicula{

    private:

    public:
        void eliminarPelicula(string titulo);

};




#endif