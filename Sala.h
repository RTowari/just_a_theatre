#ifndef SALA_H
#define SALA_H

#include <string>
using namespace std;

class Sala {
private:
    int id;
    int capacidad;

public:
    Sala();
    Sala(int, int);
    ~Sala();

    
    //no permito setear ID esto lo controla y autogenera el manejador de cines
    int getId() const;

    void setCapacidad(int);
    int getCapacidad() const;
};

#endif