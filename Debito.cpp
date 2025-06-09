#include "Debito.h"             
#include <string>

Debito::Debito() : Pago(0.0f), banco(""){}

Debito::Debito(string banco, float montoBase) : Pago (montoBase), banco(banco){}

float Debito::calcularMontoFinal(){
    return montoBase;
}

string Debito::getBanco(){
    return banco;
}

void Debito::setBanco(string banco){
    this->banco = banco;
}