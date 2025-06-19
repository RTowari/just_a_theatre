#include "DtSala.h"
#include "DtFuncion.h"

#include <map>

using namespace std;

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

map<int, DtFuncion> DtSala::getDtFunciones(){
	return funciones;
}
void DtSala::agregarDtFuncion(DtFuncion funcion){
	funciones[funcion.getId()]=funcion;
}

DtSala::~DtSala() {}

