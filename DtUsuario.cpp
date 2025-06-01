#include "DtUsuario.h"
DtUsuario::DtUsuario(){}
DtUsuario::DtUsuario(string nickname, string contrasenia, string urlFoto){
    this->nickname=nickname;
    this->contrasenia=contrasenia;
    this->urlFoto=urlFoto;
}

string DtUsuario::getNickname(){
    return this->nickname;
}
string DtUsuario::getContrasenia(){
    return this->contrasenia;
}
string DtUsuario::getUrlFoto(){
    return this->urlFoto;
}
