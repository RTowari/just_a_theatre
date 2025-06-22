#include "DtComentario.h"

DtComentario::DtComentario(){}

DtComentario::DtComentario(string texto, string cr, string u){
    this->texto = texto;
    this->comentarioRespondido = cr;
    this->nomUsuario = u;
}

DtComentario::~DtComentario(){}

string DtComentario::getTexto(){
    return texto;
}
    
string DtComentario::getComentarioRespondido(){
    return comentarioRespondido;
}

string DtComentario::getUsuario(){
    return nomUsuario;
}
