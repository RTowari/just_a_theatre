#include "ControladorComentarPelicula.h"

#include "ManejadorPelicula.h"
#include "Pelicula.h"
#include "Sesion.h"
#include <iostream>

vector<DtPelicula> ControladorComentarPelicula::listarPeliculas(){
    
    vector<DtPelicula> DtPeliculas;
    list<Pelicula*> peliculas = ManejadorPelicula::getInstancia()->getPeliculas();

    for (auto it = peliculas.begin(); it != peliculas.end(); ++it) {
        DtPeliculas.push_back((*it)->getDt());
    }

    return DtPeliculas;
}

vector<DtComentario> ControladorComentarPelicula::listarComentarios(string titulo){
    
    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);

    vector<Comentario*> aux = p->getComentarios();
    vector<DtComentario> DtComentarios;    
  
    for(int i = 0; i < aux.size(); i++){
        DtComentarios.push_back(aux[i]->getDt());
    }
    
    return DtComentarios;
}

void ControladorComentarPelicula::comentarPelicula(string titulo, string textoComentario, int respondido){

    Pelicula* p = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
    Usuario* u = Sesion::getInstancia()->getUsuario();

    Comentario* c = new Comentario(textoComentario, u);

    if(respondido > -1){  //recibe un parametro que indica la posición del comentario en la colección, si es -1 es porque no responde.
        c->setComentarioRespondido(p->getComentarios()[respondido]); 
    }

    p->agregarComentario(c);

}