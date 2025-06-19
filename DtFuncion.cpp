#include "DtFuncion.h"

DtFuncion::DtFuncion() {}

DtFuncion::DtFuncion(int id, DtFecha f, DtHorario h) {
    this->id = id;
    this->f = f;
    this->h = h;
}

int DtFuncion::getId() {
    return this->id;
}

DtFecha DtFuncion::getFecha() {
    return this->f;
}

DtHorario DtFuncion::getHorario() {
    return this->h;
}

list<DtReserva> DtFuncion::getReservas() {
    return this->reservas;
}


void DtFuncion::addReserva(DtReserva reserva) {
    reservas.push_back(reserva);
}
