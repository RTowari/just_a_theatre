#include "DtDireccion.h"

#include <string>

DtDireccion::DtDireccion() {}

DtDireccion::DtDireccion(string calle, int numero) {
    this->calle = calle;
    this->numero = numero;
}

string DtDireccion::getCalle() const{
	return this->calle;
}
int DtDireccion::getNumero() const{
	return this->numero;
}

DtDireccion::~DtDireccion(){}
