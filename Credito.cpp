#include "Credito.h"
#include "DtPago.h"
#include "DtCredito.h"

Credito::Credito(string financiera, float descuento, int cantidadEntradas)
    : Pago(PRECIO_BASE, cantidadEntradas), financiera(financiera), descuento(descuento) {}

int Credito::procesarPago() {
    float precioConDescuento = precioBase * cantidadEntradas * (1 - descuento);
    total = static_cast<int>(precioConDescuento);
    return total;
}

string Credito::getFinanciera() {
    return financiera;
}

float Credito::getDescuento() {
    return descuento;
}

DtPago* Credito::getDt() {
    // Assuming Credito has these members: precioBase, cantidadEntradas, total, financiera, descuento
    return new DtCredito(precioBase, cantidadEntradas, total, financiera, descuento);
}