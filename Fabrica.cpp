#include "Fabrica.h"
#include "ControladorSesion.h"
#include "ControladorAltaUsuario.h"
#include "ControladorAltaPelicula.h"

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

Fabrica::~Fabrica(){}

