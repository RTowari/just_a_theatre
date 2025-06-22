#include "Comentario.h"
#include "DtComentario.h"

Comentario::Comentario() {
    texto = "";
    this->comentarioRespondido = NULL;
}

Comentario::Comentario(string texto) {
    this->texto = texto;
}

Comentario::~Comentario(){}

string Comentario::getTexto() {
    return texto;
}

Comentario* Comentario::getComentarioRespondido(){
    return comentarioRespondido;
}

Usuario* Comentario::getUsuario(){
    return this->usuario;
}

void Comentario::setTexto(string texto) {
    this->texto = texto;
}

void Comentario::setComentarioRespondido(Comentario* cr) {
    this->comentarioRespondido = cr;
}

void Comentario::setUsuario(Usuario* u){
    this->usuario = u;
}

DtComentario Comentario::getDt(){
    if(this->comentarioRespondido != NULL)
        return DtComentario(this->texto, this->comentarioRespondido->getTexto(), this->usuario->getNickname());
    else 
        return DtComentario(this->texto, "", this->usuario->getNickname());
}
