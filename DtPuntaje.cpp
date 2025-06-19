#include "DtPuntaje.h"

DtPuntaje::DtPuntaje(){}

DtPuntaje::DtPuntaje(int puntaje, DtUsuario* usuario){
    this->puntaje = puntaje;
    this->usuario = usuario;
}

DtPuntaje::~DtPuntaje(){}

int DtPuntaje::getPuntaje(){
    return puntaje;
}

DtUsuario* DtPuntaje::getUsuario(){
    return usuario;
}
    
