#include "Reserva.h"
#include "Pago.h"
#include "Usuario.h"

Reserva::Reserva(){}
Reserva::Reserva(int IdReserva, Pago* mePago, Usuario* usuario) {
    this->IdReserva = IdReserva;
    this->mePago = mePago;
    this->usuario = usuario;
};

int Reserva::getIdReserva(){
    return this->IdReserva;
}
void Reserva::setIdReserva(int IdReserva)
{
    this->IdReserva = IdReserva;
}

Usuario* Reserva::getUsuario(){
    return this->usuario;
}
void Reserva::setUsuario(Usuario*){
    this->usuario=usuario;
}

Pago* Reserva::getPago(){
    return this->mePago;
}
void Reserva::setPago(Pago* pago){
    this->mePago=mePago;
}

Reserva::~Reserva() {
    delete mePago;  // free allocated payment object
}