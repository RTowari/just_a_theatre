#include "Fabrica.h"
#include "ControladorSesion.h"

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

Fabrica::~Fabrica(){}

