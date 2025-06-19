#ifndef DTCREDITO_H
#define DTCREDITO_H

#include "DtPago.h"
#include <string>

using namespace std;

class DtCredito : public DtPago {
private:
    string financiera;
    float descuento;

public:
    DtCredito();
    DtCredito(int precioBase, int cantidadEntradas, int total, string financiera, float descuento);

    string getFinanciera();
    float getDescuento();

    DtPago* getDt() const override; 
};

#endif
