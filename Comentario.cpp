#include "Comentario.h"
#include "DtComentario.h"

Comentario::Comentario() {
    texto = "";
    this->comentarioRespondido = NULL;
    this->usuario = NULL;
}
Comentario::Comentario(string texto, Usuario* usuario) {
    this->texto = texto;
    this->usuario = usuario;
}
Comentario::Comentario(string texto, Usuario* usuario, Comentario* comentario) {
    this->texto = texto;
    this->usuario = usuario;
    this->comentarioRespondido = comentario;
}

Comentario::~Comentario(){}

void Comentario::setTexto(string texto) {
    this->texto = texto;
}

void Comentario::setComentarioRespondido(Comentario* cr) {
    this->comentarioRespondido = cr;
}

void Comentario::setUsuario(Usuario* u) {
    this->usuario = u;
}

string Comentario::getTexto() {
    return texto;
}

Comentario* Comentario::getComentarioRespondido(){
    return comentarioRespondido;
}

Usuario* Comentario::getUsuario(){
    return usuario;
}

DtComentario Comentario::getDt(){
    
    if(this->comentarioRespondido != NULL)
        return DtComentario(this->texto, this->comentarioRespondido->getTexto());
    else 
        return DtComentario(this->texto, "");

}
