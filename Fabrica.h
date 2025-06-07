#ifndef FABRICA
#define FABRICA
#include "IControladorSesion.h"
#include "IControladorAltaUsuario.h"
#include "IControladorAltaPelicula.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        
        IControladorSesion* getIControladorSesion();
        
        IControladorAltaUsuario* getIControladorAltaUsuario();
        
        IControladorAltaPelicula* getIControladorAltaPelicula();

        ~Fabrica();


};
#endif