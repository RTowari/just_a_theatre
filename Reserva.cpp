#include "Reserva.h"
#include "Pago.h"
#include "Usuario.h"

Reserva::Reserva(){}
Reserva::Reserva(int IdReserva, int cantEntradas, float costo, Pago* mePago) {
    this->IdReserva = IdReserva;
    this->cantEntradas = cantEntradas;
    this->costo = costo;
    this->mePago = mePago;

};

int Reserva::getIdReserva(){
    return this->IdReserva;
}
void Reserva::setIdReserva(int IdReserva)
{
    this->IdReserva = IdReserva;
}

int Reserva::getCantEntradas(){
    return this->cantEntradas;
}
void Reserva::setCantEntradas(int cantEntradas){
    this->cantEntradas = cantEntradas;
}

float Reserva::getCosto(){
    return this->costo;
}
void Reserva::setCosto(float){
    this-> costo = costo;
}






Reserva::~Reserva() {}