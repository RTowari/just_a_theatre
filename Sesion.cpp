#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){
    usuarioLogueado = NULL;
}

Sesion* Sesion::getInstancia(){
    if (instancia == NULL) {
        instancia = new Sesion();
    }
    return instancia;
}

void Sesion::setUsuario(Usuario* u){
    usuarioLogueado = u;
}

Usuario* Sesion::getUsuario(){
    return usuarioLogueado;
}

void Sesion::cerrarSesion(){
    usuarioLogueado = NULL;
}

Sesion::~Sesion() {}