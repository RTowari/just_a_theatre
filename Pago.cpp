#include "Pago.h"

Pago::Pago(int precioBase, int cantidadEntradas)
    : precioBase(precioBase), cantidadEntradas(cantidadEntradas), total(0) {}

int Pago::getPrecioBase() {
    return precioBase;
}

int Pago::getTotal() {
    return total;
}

Pago::~Pago() {}