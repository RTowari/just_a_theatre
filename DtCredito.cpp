#include "DtCredito.h"

DtCredito::DtCredito() {}

DtCredito::DtCredito(int precioBase, int cantidadEntradas, int total, string financiera, float descuento)
    : DtPago(precioBase, cantidadEntradas, total) {
    this->financiera = financiera;
    this->descuento = descuento;
}

string DtCredito::getFinanciera() {
    return this->financiera;
}

float DtCredito::getDescuento() {
    return this->descuento;
}

// Credito.cpp
DtPago* DtCredito::getDt() const {
    return new DtCredito(
        this->precioBase,         // int precioBase
        this->cantidadEntradas,   // int cantidadEntradas
        this->total,              // int total
        this->financiera,         // string financiera
        this->descuento           // float descuento
    );
}

