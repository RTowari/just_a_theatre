#include "Pelicula.h"
#include <list>
#include "ManejadorPelicula.h"
#include <iostream>

using namespace std;

ManejadorPelicula* ManejadorPelicula::instancia = NULL;

ManejadorPelicula::ManejadorPelicula(){}

ManejadorPelicula* ManejadorPelicula::getInstancia(){
    if(instancia == NULL)
        instancia = new ManejadorPelicula();
    return instancia;
}

list<Pelicula*> ManejadorPelicula::getPeliculas(){
    list<Pelicula*> lstPeliculas;
    for (map<string,Pelicula*>::iterator it=this->peliculas.begin(); it!=peliculas.end(); ++it)
        lstPeliculas.push_back(it->second);
    return lstPeliculas;
}

Pelicula* ManejadorPelicula::buscarPelicula(string nickname){
    map<string,Pelicula*>::iterator it = this->peliculas.find(nickname);
    return it->second;
}

void ManejadorPelicula::agregarPelicula(Pelicula* pelicula){
    peliculas.insert(std::pair<string,Pelicula*>(pelicula->getTitulo(), pelicula));
}

bool ManejadorPelicula::existePelicula(string nickname){
    map<string,Pelicula*>::iterator it = this->peliculas.find(nickname);
    return (it != this->peliculas.end());
}

void ManejadorPelicula::eliminarPelicula(string nickname){
    map<string,Pelicula*>::iterator it = this->peliculas.find(nickname);
    this->peliculas.erase(it);
}

void ManejadorPelicula::verPeliculas(){

    if(peliculas.empty()){
       throw runtime_error("No hay peliculas cargadas.");
    }else{
        for(map<string,Pelicula*>::iterator it = this->peliculas.begin(); it!=peliculas.end(); ++it){
            cout << it->first << "\n" << endl;
        }
    }
}

ManejadorPelicula::~ManejadorPelicula(){}
