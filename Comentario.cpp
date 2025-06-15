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

void Comentario::setTexto(string texto) {
    this->texto = texto;
}

void Comentario::setComentarioRespondido(Comentario* cr) {
    this->comentarioRespondido = cr;
}

DtComentario Comentario::getDt(){
    
    if(this->comentarioRespondido != NULL)
        return DtComentario(this->texto, this->comentarioRespondido->getTexto());
    else 
        return DtComentario(this->texto, "");
}
