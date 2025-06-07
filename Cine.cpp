#include "Cine.h"
Cine::Cine(){}
Cine::Cine(int id,string direccion){
	this->id=id;
	this->direccion=direccion;
    this->topeSalas=0;
}
int Cine::getId(){
	return this->id;
}
    //no permito setear ID esto lo controla y autogenera el manejador de cines

string Cine::getDireccion(){
	return this->direccion;
}
void Cine::setDireccion(string direccion){
	this->direccion=direccion;
}
Cine::~Cine(){
	for(int i = 0;i<this->topeSalas;i++){
		delete this->salas[i];
        this->salas[i] = nullptr ;
    }
}

void Cine::agregarSala(Sala* sala){
	this->salas[this->topeSalas]=sala;
	this->topeSalas++;
}
int Cine::getTopeSalas(){
	return this->topeSalas;
}
Sala** Cine::obtenerSalas(){
	Sala** salas = new Sala*[this->topeSalas];
	for(int i=0;i<this->topeSalas;i++)
		salas[i]=this->salas[i];
	return salas;
}
