#include "DtDebito.h"

DtDebito::DtDebito() {}

DtDebito::DtDebito(int precioBase, int cantidadEntradas, int total, string banco)
    : DtPago(precioBase, cantidadEntradas, total) {
    this->banco = banco;
}

string DtDebito::getBanco() {
    return this->banco;
}

DtPago* DtDebito::getDt() const {
    return new DtDebito(precioBase, cantidadEntradas, total, banco);
}
