#include "Debito.h"

Debito::Debito(string banco, int cantidadEntradas)
    : Pago(PRECIO_BASE, cantidadEntradas), banco(banco) {}

int Debito::procesarPago() {
    total = precioBase * cantidadEntradas;  // Sin descuento
    return total;
}

string Debito::getBanco() {
    return banco;
}

DtPago* Debito::getDt() {

    return new DtDebito(precioBase, cantidadEntradas, total, banco);
}