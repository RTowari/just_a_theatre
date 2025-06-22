#include "Puntaje.h"

using namespace std;

Puntaje::Puntaje() {
    puntaje = 0;
}

Puntaje::Puntaje(int puntaje, Usuario* usuario) {
    this->puntaje = puntaje;
    this->usuario = usuario;
}

Puntaje::~Puntaje(){}

int Puntaje::getPuntaje() {
    return puntaje;
}

void Puntaje::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

void Puntaje::setUsuario(Usuario* u) {
    this->usuario = u;
}

Usuario* Puntaje::getUsuario(){
    return usuario;
}

DtPuntaje Puntaje::getDt() {
    //llamo constructor DtUsuario
    DtUsuario* dtU = new DtUsuario(this->usuario->getNickname(), this->usuario->getContrasenia(), this->usuario->getUrlFoto()); 
    return DtPuntaje(this->puntaje, dtU);
}