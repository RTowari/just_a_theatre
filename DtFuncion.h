#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "DtFecha.h"
#include "DtHorario.h"
#include "DtReserva.h"
#include <list>

using namespace std;

class DtFuncion {
private:
    int id;
    DtFecha f;
    DtHorario h;
    list<DtReserva> reservas;  // Direct ownership (value type)

public:
    DtFuncion();
    DtFuncion(int id, DtFecha f, DtHorario h);

    int getId();
    DtFecha getFecha();
    DtHorario getHorario();
    list<DtReserva> getReservas();  // returns copy

    void addReserva(DtReserva reserva);
};

#endif
