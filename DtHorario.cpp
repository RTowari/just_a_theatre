#include "DtHorario.h"

DtHorario::DtHorario() {}

DtHorario::DtHorario(int mComienzo, int hComienzo, int mFin, int hFin) {
    this->mComienzo = mComienzo;
    this->hComienzo = hComienzo;
    this->mFin = mFin;
    this->hFin = hFin;
}


int DtHorario::getHoraComienzo(){
    return this->hComienzo;
}
int DtHorario::getMinutoComienzo(){
    return this->mComienzo;
}

int DtHorario::getHoraFin(){
    return this->hFin;
}
int DtHorario::getMinutoFin(){
    return this->mFin;
}
