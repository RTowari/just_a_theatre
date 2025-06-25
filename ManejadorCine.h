#ifndef MANEJADOR_CINE_H
#define MANEJADOR_CINE_H

#include "Cine.h" 
#include <map>    
#include <list>   
#include <string> 
#include <vector> 

using namespace std;

class ManejadorCine {
private:
    static ManejadorCine* instancia;
    map<int, Cine*> cines;
    // Atributo para la autogeneración de IDs de cine y sala.
    int ultimoIdCine;
    // Constructor privado para el singleton.
    ManejadorCine();


public:
    static ManejadorCine* getInstancia();
    list<Cine*> getCines();
    int getSiguienteIdCine();
    void darDeAltaCine(Cine* cine);
    bool existeCine(int id);
    void eliminarCine(int id);
    void eliminarPeliculaDeCines(string titulo);
    virtual ~ManejadorCine();

    bool existePelicula(string titulo);                                      // Para CU AltaFuncion
    Cine* buscarCine(int idCine);
};

#endif 