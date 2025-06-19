#ifndef DTSALA_H
#define DTSALA_H

#include "DtFuncion.h"

#include <string>
#include <map>

using namespace std;

class DtSala {
private:
    int id;
    int capacidad;
    map<int, DtFuncion> funciones;

public:
    DtSala();
    DtSala(int, int);
      
    int getId();
    int getCapacidad();

    map<int, DtFuncion> getDtFunciones();
    void agregarDtFuncion(DtFuncion);

    ~DtSala(); 
};

#endif