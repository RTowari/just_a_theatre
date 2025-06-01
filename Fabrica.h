#ifndef FABRICA
#define FABRICA
#include "IControladorSesion.h"
#include "IControladorAltaUsuario.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControladorSesion* getIControladorSesion();
        
        IControladorAltaUsuario* getIControladorAltaUsuario();
        
        ~Fabrica();


};
#endif