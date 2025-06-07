#ifndef CONTROLADORELIMINARPELICULA
#define CONTROLADORELIMINARPELICULA

#include "Pelicula.h"
#include "IControladorEliminarPelicula.h"

class ControladorEliminarPelicula : public IControladorEliminarPelicula{

    private:

    public:
        void altaPelicula(string titulo);

};




#endif