#ifndef CINE_H
#define CINE_H
#define CANT_SALAS 20
#include "Sala.h"
#include <string>
using namespace std;

class Cine {
private:
    int id;
    string direccion;
    Sala* salas[CANT_SALAS];
    int topeSalas;

public:
    Cine();
    Cine(int, string);
    ~Cine();

    //no permito setear ID esto lo controla y autogenera el manejador de cines
    void setDireccion(string);

    int getId();
    string getDireccion();

    void agregarSala(Sala*);
	Sala** obtenerSalas();
	int getTopeSalas();
};

#endif
