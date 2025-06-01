#include "Usuario.h"

Usuario::Usuario(){}
Usuario::Usuario(string nickname, string contrasenia, string url){
    this->nickname=nickname;
    this->contrasenia=contrasenia;
    this->urlFoto=urlFoto;
}
string Usuario::getNickname(){
    return this->nickname;
}
void Usuario::setNickname(string nickname){
    this->nickname=nickname;
}

string Usuario::getContrasenia(){
    return this->contrasenia;
}
void Usuario::setContrasenia(string contrasenia){
    this->contrasenia=contrasenia;
}

string Usuario::getUrlFoto(){
    return this->url;
}
void Usuario::setUrlFoto(){
    this->urlFoto=urlFoto;
}