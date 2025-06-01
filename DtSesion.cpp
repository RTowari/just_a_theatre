#include "DtSesion.h"

DtSesion::DtSesion(){}

DtSesion::DtSesion(string nickname, string contrasenia){
    this->nickname = nickname;
    this->contrasenia = contrasenia;
}

string DtSesion::getNickname(){
    return nickname;
}

string DtSesion::getContrasenia(){
    return contrasenia;
}

DtSesion::~DtSesion(){}