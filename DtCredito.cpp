#include "DtCredito.h"
#include <string>


DtCredito::DtCredito() : financiera(""), porcentajeDescuento(0.0f), montoBase(0.0f){}

DtCredito::DtCredito(std::string financiera, float porcentajeDescuento, float montoBase)
    : financiera(financiera), porcentajeDescuento(porcentajeDescuento), montoBase(montoBase){}

string DtCredito::getFinanciera(){
    return financiera;
}

void DtCredito::setFinanciera(string financiera){
    this->financiera = financiera;
}

float DtCredito::getPorcentajeDescuento(){
    return porcentajeDescuento;
}

void DtCredito::setPorcentajeDescuento(float porcentajeDescuento) {
    this->porcentajeDescuento = porcentajeDescuento;
}

float DtCredito::getMontoBase(){
    return montoBase;
}

void DtCredito::setMontoBase(float montoBase){
    this->montoBase = montoBase;
}