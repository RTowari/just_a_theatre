#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorSesion.h"
#include "IControladorAltaUsuario.h"
#include "IControladorAltaPelicula.h"
#include "IControladorCrearReserva.h"
#include "IControladorAltaCine.h"
#include "IControladorEliminarPelicula.h"
#include "IControladorComentarPelicula.h"
#include "IControladorAltaFuncion.h"

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

        IControladorEliminarPelicula* getIControladorEliminarPelicula();

        IControladorComentarPelicula* getIControladorComentarPelicula();

        IControladorAltaFuncion* getIControladorAltaFuncion();

        ~Fabrica();


};

#endif