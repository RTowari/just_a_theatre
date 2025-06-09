#ifndef DT_DEBITO_H
#define DT_DEBITO_H
#include <string>
using namespace std;

class DtDebito{
private:
    string banco;
    float montoBase;

public:
    DtDebito();
    DtDebito(string banco, float montoBase);

    std::string getBanco();
    void setBanco(string banco);

    float getMontoBase();
    void setMontoBase(float montoBase);
};

#endif