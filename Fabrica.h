#ifndef FABRICA
#define FABRICA
#include "IControladorSesion.h"
#include "IControladorAltaUsuario.h"
#include "IControladorAltaPelicula.h"
#include "IControladorCrearReserva.h"
#include "IControladorAltaCine.h"


class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        
        IControladorSesion* getIControladorSesion();
        
        IControladorAltaUsuario* getIControladorAltaUsuario();
        
        IControladorAltaPelicula* getIControladorAltaPelicula();

        IControladorCrearReserva* getIControladorCrearReserva();

        IControladorAltaCine* getIControladorAltaCine();

        ~Fabrica();


};
#endif