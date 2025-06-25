#ifndef CINE_H
#define CINE_H
#define CANT_SALAS 30

#include "DtDireccion.h"
#include "DtCine.h"
#include "Sala.h"
#include "Pelicula.h"

#include <map>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Cine {
private:
    int id;
    DtDireccion dtDireccion;
    Sala* salas[CANT_SALAS];
    int topeSalas;
    map<string,Pelicula*> peliculas;

public:
    Cine();
    Cine(int, DtDireccion);
    ~Cine();

    //no permito setear ID esto lo controla y autogenera el manejador de cines
    void setDireccion(DtDireccion dtDireccion);

    int getId();
    DtDireccion getDireccion() const;

    // Funciones para controlar las peliculas del cine
    void agregarPelicula(Pelicula* pelicula);               
    void eliminarPeliculaCine(string titulo);               //cu eliminarPelicula
    void eliminarPeliculaDeFunciones(string titulo);        //cu eliminarPelicula

    //cu AltaFuncion
    bool existePelicula(string titulo);
    DtCine getDt();
    
    // Operaciones que manejan salas
	int getTopeSalas();
    void agregarSala(Sala*);
    Sala* obtenerSalaPorId(int id);         
    std::vector<Sala*> obtenerSalas();

    // cu crearReserva
    list<DtSala> obtenerSalasPorPelicula(string);
    list <DtSala> obtenerSalasPorPeliculaYFecha(string);

};

#endif
