#ifndef FUNCION_H
#define FUNCION_H

#include <list>

#include "DtFecha.h"
#include "DtHorario.h"
#include "Reserva.h"

using namespace std;

class Funcion{

    private:
        int id;
        DtFecha* fecha;
        DtHorario* horario;
        list<Reserva*> reservas;
    public:
        Funcion();
        Funcion(int,DtFecha*,DtHorario*);
        ~Funcion();

        void setId(int);
        void setFecha(DtFecha*);
        void setHorario(DtHorario*);

        int getId();
        DtFecha* getFecha();
        DtHorario* getHorario();

        void agregarReserva(Reserva*);
        list<Reserva*> getReservas();
};

#endif