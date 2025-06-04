#include "Funcion.h"

Funcion::Funcion(){}
Funcion::Funcion(int id, DtFecha* f, DtHorario* h){
    this->id = id;
    this->fecha = f;
    this->horario = h;
}
Funcion::~Funcion(){}

void Funcion::setId(int id){
    this->id = id;
}

void Funcion::setFecha(DtFecha* f){
    this->fecha = f;
}

void Funcion::setHorario(DtHorario* h){
    this->horario = h;
}

int Funcion::getId(){
    return this->id;
}

DtFecha* Funcion::getFecha(){
    return this->fecha;
}

DtHorario* Funcion::getHorario(){
    return this->horario;
}