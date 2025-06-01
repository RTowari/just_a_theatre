#ifndef FABRICA
#define FABRICA
#include "iControladorSesion.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControladorSesion* getIControladorSesion();
        ~Fabrica();
};
#endif