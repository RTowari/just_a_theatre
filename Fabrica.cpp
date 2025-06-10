#include "Fabrica.h"
#include "ControladorSesion.h"
#include "ControladorAltaUsuario.h"
#include "ControladorAltaPelicula.h"
#include "ControladorCrearReserva.h"
#include "ControladorAltaCine.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL) 
        instancia = new Fabrica();
    return instancia;
}

IControladorSesion* Fabrica::getIControladorSesion(){
    return new ControladorSesion();    
}

IControladorAltaUsuario* Fabrica::getIControladorAltaUsuario(){
    return new ControladorAltaUsuario();    
}

<<<<<<< HEAD
IControladorAltaPelicula* Fabrica::getIControladorAltaPelicula(){
    return new ControladorAltaPelicula();    
}

IControladorCrearReserva* Fabrica::getIControladorCrearReserva(){
    return new ControladorCrearReserva();
}

IControladorAltaCine* Fabrica::getIControladorAltaCine(){
    return new ControladorAltaCine();
}


=======
>>>>>>> parent of 78acd6f (semi implementados los alta en el back)
Fabrica::~Fabrica(){}

