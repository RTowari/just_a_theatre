#include "ControladorVerComentariosyPuntajesdePelicula.h"
#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include "Sesion.h"
#include <iostream>

vector<DtPelicula> ControladorVerComentariosyPuntajesdePelicula::listarPeliculas(){
    
    vector<DtPelicula> DtPeliculas;
    list<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();

    for (auto it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPeliculas.push_back((*it)->getDt());
    }

    return DtPeliculas;
}

DtInfoPelicula* ControladorVerComentariosyPuntajesdePelicula::obtenerInfoPelicula(string titulo){
    ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
    Pelicula* pelicula = mp->buscarPelicula(titulo);
    
    if (pelicula == nullptr) {
        return nullptr; // No se encontró la película
    }
    DtPelicula* dtPeliculaInfo = new DtPelicula(pelicula->getTitulo(), pelicula->getSinopsis(), pelicula->CalculaPuntajePromedio(), pelicula->getPoster());

    //se obtiene comentarios y convertirlos a DtComentario
    vector<DtComentario> dtComentarios;
    for (Comentario* c : pelicula-> getComentarios()) {
        dtComentarios.push_back(c->getDt()); 
    }
    //se obtiene puntajes y convertirlos a DtPuntaje
    vector<DtPuntaje> dtPuntajes;
    for (Puntaje* p : pelicula->getPuntajes()) {
        dtPuntajes.push_back(p->getDt()); 
    }

    //cantidad de usuarios que puntuaron
    int cantidadPuntajes = pelicula->getPuntajes().size();

    //Crear y devolver el DtInfoPelicula con toda la información consolidada
    return new DtInfoPelicula(dtPeliculaInfo, cantidadPuntajes, dtComentarios, dtPuntajes);
}
