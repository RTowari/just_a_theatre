#ifndef DT_CREDITO_H
#define DT_CREDITO_H
#include <string>
using namespace std;

class DtCredito{
private:
    string financiera;
    float porcentajeDescuento;
    float montoBase;

public:
    DtCredito();
    DtCredito(string financiera, float porcentajeDescuento, float montoBase);

    string getFinanciera();
    void setFinanciera(string financiera);

    float getPorcentajeDescuento();
    void setPorcentajeDescuento(float porcentajeDescuento);

    float getMontoBase();
    void setMontoBase(float montoBase);
};

#endif