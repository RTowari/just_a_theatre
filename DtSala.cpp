#include "DtSala.h"
DtSala::DtSala(){}
DtSala::DtSala(int id,int capacidad){
	this->id=id;
	this->capacidad=capacidad;
}
int DtSala::getId(){
	return this->id;
}

int DtSala::getCapacidad(){
	return this->capacidad;
}
DtSala::~DtSala() {}

