#include "DtDebito.h"
#include <string>


DtDebito::DtDebito() : banco(""), montoBase(0.0f){}

DtDebito::DtDebito(string banco, float montoBase) : banco(banco), montoBase(montoBase){}

string DtDebito::getBanco(){
    return banco;
}

void DtDebito::setBanco(string banco){
    this->banco = banco;
}

float DtDebito::getMontoBase(){
    return montoBase;
}