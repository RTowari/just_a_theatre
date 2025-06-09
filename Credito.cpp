#include "Credito.h"
#include <string>


Credito::Credito(string financiera, float porcentajeDescuento, float montoBase) : Pago(montoBase), financiera(financiera), porcentajeDescuento(porcentajeDescuento) {}

float Credito::calcularMontoFinal() {
    
    return montoBase * (1 - porcentajeDescuento / 100.0f);
}

string Credito::getFinanciera() {
    return financiera;
}

void Credito::setFinanciera(string financiera) {
    this->financiera = financiera;
}

float Credito::getPorcentajeDescuento() {
    return porcentajeDescuento;
}

void Credito::setPorcentajeDescuento(float porcentajeDescuento) {
    this->porcentajeDescuento = porcentajeDescuento;
}
