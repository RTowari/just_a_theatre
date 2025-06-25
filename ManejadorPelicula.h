#ifndef MANEJADOR_PELICULA
#define MANEJADOR_PELICULA
#include "Pelicula.h"

#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorPelicula{
    private:
        static ManejadorPelicula* instancia;
        map<string,Pelicula*> peliculas;
        ManejadorPelicula();
    public:
        static ManejadorPelicula* getInstancia();
        list<Pelicula*> getPeliculas();
        Pelicula* buscarPelicula(string);
        void agregarPelicula(Pelicula*);
        bool existePelicula(string);
        void eliminarPelicula(string);              //cu eliminarPelicula
        virtual ~ManejadorPelicula();
};
#endif