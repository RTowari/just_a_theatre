#include "DtCine.h"
#include "DtDireccion.h"

DtCine::DtCine() {}

DtCine::DtCine(int id, DtDireccion direccion) {
    this->id = id;
    this->direccion = direccion;
    this->topeSalas = 0;
}
DtCine::DtCine(DtDireccion direccion) {
    this->direccion = direccion;
    this->topeSalas = 0;
}

int DtCine::getId() {
    return this->id;
}

DtDireccion DtCine::getDireccion() const {
    return this->direccion;
}

int DtCine::getTopeSalas() {
    return this->topeSalas;
}