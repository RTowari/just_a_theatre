#include "DtHorario.h"

DtHorario::DtHorario() {
    horaComienzo = "";
    horaFin = "";
}

DtHorario::DtHorario(string comienzo, string fin) {
    horaComienzo = comienzo;
    horaFin = fin;
}

void DtHorario::setHoraComienzo(string comienzo) {
    horaComienzo = comienzo;
}

void DtHorario::setHoraFin(string fin) {
    horaFin = fin;
}

string DtHorario::getHoraComienzo() {
    return horaComienzo;
}

string DtHorario::getHoraFin() {
    return horaFin;
}
