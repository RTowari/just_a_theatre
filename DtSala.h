#ifndef DTSALA_H
#define DTSALA_H

#include <string>
using namespace std;

class DtSala {
private:
    int id;
    int capacidad;

public:
    DtSala();
    DtSala(int, int);
    ~DtSala();   
    //no permito setear ID esto lo controla y autogenera el manejador de cines
    int getId();
    int getCapacidad();
};

#endif