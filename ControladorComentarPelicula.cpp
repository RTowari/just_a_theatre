#include "ControladorComentarPelicula.h"

#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include "Sesion.h"
#include <iostream>

vector<DtPelicula> ControladorComentarPelicula::listarPeliculas(){
    //obtiene las peliculas de manejadorPelicula
    //retorna coleccion de DtPeliculas

    vector<DtPelicula> DtPeliculas;
    list<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();

    for (auto it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPeliculas.push_back((*it)->getDt());
    }

    return DtPeliculas;
}


vector<DtComentario> ControladorComentarPelicula::listarComentarios(string titulo){
    //obtiene los comentarios de la pelicula y los pasa a dtcomentario
    //retorna una coleccion dtcomentario

    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);

    vector<Comentario*> aux = p->getComentarios();
    vector<DtComentario> DtComentarios;    
  
    for(int i = 0; i < aux.size(); i++){
        DtComentarios.push_back(aux[i]->getDt());
    }
    
    return DtComentarios;
}

void ControladorComentarPelicula::comentarPelicula(string titulo, string textoComentario, int respondido){
    //agrega el comentario según los parametros obtenidos

    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    Usuario* u = Sesion::getInstancia()->getUsuario();
    Comentario* c = new Comentario();

    c->setTexto(textoComentario);
    c->setUsuario(u);

    if(respondido > 0){    //si es mayor a -1 está respondiendo a otro comentario
        c->setComentarioRespondido(p->getComentarios()[respondido]); //accede al comentario x indice mediante la variable "respondido"
    }else{
        c->setComentarioRespondido(NULL);
    }

    p->agregarComentario(c);
}