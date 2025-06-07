#ifndef DTCINE_H
#define DTCINE_H
#define CANT_SALAS 20
#include "DtSala.h"
#include <string>
using namespace std;

class DtCine {
private:
    int id;
    string direccion;
    DtSala* salas[CANT_SALAS];
    int topeSalas;

public:
    DtCine();
    DtCine(int, string);
    ~DtCine();
    int getId();
    string getDireccion() const;
	DtSala** obtenerSalas();
	int getTopeSalas();
};

#endif
