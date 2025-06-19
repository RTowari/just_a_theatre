#include "RelojLocal.h"
#include <list>

using namespace std;

RelojLocal* RelojLocal::instancia=NULL;

RelojLocal::RelojLocal(){}

RelojLocal* RelojLocal::getInstancia(){
    if(instancia == NULL)
        instancia = new RelojLocal();
    return instancia;
}

void RelojLocal::setAnio(int año){
    this-> año = año;
}
void RelojLocal::setMes(int mes){
    this-> mes = mes;
}
void RelojLocal::setDia(int dia){
    this -> dia = dia;
}
void RelojLocal::setHora(int hora){
    this->hora = hora;
}
void RelojLocal::setMinuto(int minuto){
    this->minuto = minuto;
}

int RelojLocal::getAnio(){
    return this->año;
}
int RelojLocal::getMes(){
    return this->mes;
}
int RelojLocal::getDia(){
    return this->dia;
}
int RelojLocal::getHora(){
    return this->hora;
}
int RelojLocal::getMinuto(){
    return this->minuto;
}