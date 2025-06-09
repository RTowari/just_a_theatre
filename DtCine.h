
#ifndef DT_CINE_H
#define DT_CINE_H

#include "DtDireccion.h"
#include <string>

class DtCine {
private:
    int id;
    DtDireccion direccion; // now DtDireccion type, not string
    int topeSalas;
public:
    DtCine();
    DtCine(DtDireccion direccion);
    DtCine(int id, DtDireccion direccion);
    
    int getId();
    DtDireccion getDireccion() const;
    int getTopeSalas();
};

#endif

