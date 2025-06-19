#ifndef SALA_H
#define SALA_H

#include "DtSala.h"
#include "Funcion.h"

#include <string>
#include <map>


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

    //para cu eliminarPelicula
    void eliminarPeliFuncion(string titulo);                
    
    //para cu AltaFuncion
    DtSala getDt();
    void agregarFuncion(Funcion* funcion);

    //cu Crear Reserva
    //cu Crear Reserva
    map<int,Funcion*> obtenerFunciones(); 
    DtSala obtenerSalaPorPelicula(string titulo);
    DtSala obtenerSalaPorPeliculaYFecha(string titulo);
};

#endif