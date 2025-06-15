#include "DtComentario.h"

DtComentario::DtComentario(){}

DtComentario::DtComentario(string texto, string cr){
    this->texto = texto;
    this->comentarioRespondido = cr;
}

DtComentario::~DtComentario(){}

string DtComentario::getTexto(){
    return texto;
}
    
string DtComentario::getComentarioRespondido(){
    return comentarioRespondido;
}
