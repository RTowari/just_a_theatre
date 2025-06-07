#include "Sala.h"
Sala::Sala(){}
Sala::Sala(int id,int capacidad){
	this->id=id;
	this->capacidad=capacidad;
}
int Sala::getId(){
	return this->id;
}
    //no permito setear ID esto lo controla y autogenera el manejador de Salas

int Sala::getCapacidad(){
	return this->capacidad;
}
void Sala::setCapacidad(int capacidad){
	this->capacidad=capacidad;
}
Sala::~Sala() {}

