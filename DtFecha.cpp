#include "DtFecha.h"

DtFecha::DtFecha() {
    dia = 1;
    mes = 1;
    anio = 1900;
}

DtFecha::DtFecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

void DtFecha::setDia(int d) {
    dia = d;
}

void DtFecha::setMes(int m) {
    mes = m;
}

void DtFecha::setAnio(int a) {
    anio = a;
}

int DtFecha::getDia() {
    return dia;
}

int DtFecha::getMes() {
    return mes;
}

int DtFecha::getAnio() {
    return anio;
}
