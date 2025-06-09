#ifndef CREDITO_H
#define CREDITO_H

#include "Pago.h"
#include <string> 

using namespace std;

class Credito : public Pago{
private:
    string financiera;
    float porcentajeDescuento;

public:
    Credito(string financiera, float porcentajeDescuento, float montoBase);
    float calcularMontoFinal();

    string getFinanciera();
    void setFinanciera(string financiera);

    float getPorcentajeDescuento();
    void setPorcentajeDescuento(float porcentajeDescuento);
};

#endif