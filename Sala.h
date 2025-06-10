#ifndef SALA_H
#define SALA_H

#include <string>
#include <map>
#include "Funcion.h"
using namespace std;

class Sala {
private:
    int id;
    int capacidad;
    map<int,Funcion*> funciones;
public:
    Sala();
    Sala(int, int);
    ~Sala();

    
    //no permito setear ID esto lo controla y autogenera el manejador de cines
    int getId() const;
    void setCapacidad(int);
    int getCapacidad() const;

    void eliminarPeliFuncion(string titulo);             //para cu eliminarPelicula
};

#endif