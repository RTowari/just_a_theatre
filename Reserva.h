#ifndef RESERVA_H
#define RESERVA_H

//#include "DtFecha.h"
//#include "DtHorario.h"

#include "Pago.h"

using namespace std;

class Reserva{
    private:
        float costo;
        int cantEntradas;
        int IdReserva;
        Pago* mePago;

    public:
        Reserva();
        Reserva(int, int, float, Pago*);
        ~Reserva();

        void setIdReserva(int);
        void setCosto(float);
        void setCantEntradas(int);

        int getIdReserva();
        float getCosto();
        int getCantEntradas();
};

#endif