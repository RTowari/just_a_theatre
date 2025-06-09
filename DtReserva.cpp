#include "DtReserva.h"

DtReserva::DtReserva(){}

DtReserva::DtReserva(int IdReserva, int cantEntradas, float costo) {
    this->IdReserva = IdReserva;
    this->cantEntradas = cantEntradas;
    this->costo = costo;
};

int DtReserva::getIdReserva(){
    return this->IdReserva;
}

int DtReserva::getCosto(){
    return this->costo;
}

int DtReserva::getCantEntradas(){
    return this->cantEntradas;
}

DtReserva::~DtReserva() {}