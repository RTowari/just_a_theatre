#ifndef DEBITO_H
#define DEBITO_H

#include "Pago.h"
#include <string>
#include "DtDebito.h"
#include "DtPago.h"

using namespace std;

class Debito : public Pago {
private:
    string banco;
    virtual DtPago* getDt() override;
public:
    Debito(string banco, int cantidadEntradas);
    virtual int procesarPago() override;
    string getBanco();
};

#endif
