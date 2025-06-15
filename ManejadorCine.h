#ifndef MANEJADOR_CINE_H
#define MANEJADOR_CINE_H

#include "Cine.h" 
#include "Sala.h" 
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
    int ultimoIdSala;
    // Constructor privado para el singleton.
    ManejadorCine();
    // Método privado para generar un nuevo ID de sala.
       int generarNuevoIdSala(); // 

public:
    static ManejadorCine* getInstancia();
    list<Cine*> getCines();
    int getSiguienteIdCine();
    Cine* buscarCine(int id);
    void darDeAltaCine(Cine* cine, const vector<int>& capacidadesSalas);
    bool existeCine(int id);
    void eliminarCine(int id);
    void eliminarPeliculaDeCines(string titulo);
    vector<Sala*> obtenerSalasDeCine(int id);
    virtual ~ManejadorCine();
};

#endif 