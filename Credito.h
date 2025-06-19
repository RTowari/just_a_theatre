#ifndef CREDITO_H
#define CREDITO_H

#include "Pago.h"
#include <string>

using namespace std;

class Credito : public Pago {
private:
    string financiera;
    float descuento;
public:
    Credito(string financiera, float descuento, int cantidadEntradas);
    virtual int procesarPago() override;
    string getFinanciera();
    float getDescuento();
    virtual DtPago* getDt() override;
};

#endif