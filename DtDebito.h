#ifndef DTDEBITO_H
#define DTDEBITO_H

#include "DtPago.h"
#include <string>

using namespace std;

class DtDebito : public DtPago {
private:
    string banco;

public:
    DtDebito();
    DtDebito(int precioBase, int cantidadEntradas, int total, string banco);

    string getBanco();

    DtPago* getDt() const override;
};

#endif
