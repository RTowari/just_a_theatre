#include "DtPago.h"

DtPago::DtPago() {}

DtPago::DtPago(int precioBase, int cantidadEntradas, int total) {
    this->precioBase = precioBase;
    this->cantidadEntradas = cantidadEntradas;
    this->total = total;
}

DtPago::~DtPago() {}

int DtPago::getPrecioBase() {
    return this->precioBase;
}

int DtPago::getCantidadEntradas() {
    return this->cantidadEntradas;
}

int DtPago::getTotal() {
    return this->total;
}
