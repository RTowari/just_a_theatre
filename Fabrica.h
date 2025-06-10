#ifndef FABRICA
#define FABRICA
#include "IControladorSesion.h"
#include "IControladorAltaUsuario.h"
<<<<<<< HEAD
#include "IControladorAltaPelicula.h"
#include "IControladorCrearReserva.h"
#include "IControladorAltaCine.h"

=======
>>>>>>> parent of 78acd6f (semi implementados los alta en el back)

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        
        IControladorSesion* getIControladorSesion();
        
        IControladorAltaUsuario* getIControladorAltaUsuario();
        
<<<<<<< HEAD
        IControladorAltaPelicula* getIControladorAltaPelicula();

        IControladorCrearReserva* getIControladorCrearReserva();

        IControladorAltaCine* getIControladorAltaCine();

=======
>>>>>>> parent of 78acd6f (semi implementados los alta en el back)
        ~Fabrica();


};
#endif