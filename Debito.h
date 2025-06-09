#ifndef DEBITO_H
#define DEBITO_H

#include "Pago.h"
#include <string> 

using namespace std;

class Debito : public Pago{
private:
    string banco;

public:
    Debito();
    Debito(string banco, float montoBase);
    float calcularMontoFinal();

    string getBanco();
    void setBanco(string banco);
};

#endif
