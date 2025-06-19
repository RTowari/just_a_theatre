#ifndef RESERVA_H
#define RESERVA_H

//#include "DtFecha.h"
//#include "DtHorario.h"

#include "Pago.h"
#include "Usuario.h"

using namespace std;

class Reserva{
    private:
        int IdReserva;
        Pago* mePago;
        Usuario* usuario;

    public:
        Reserva();
        Reserva(int, Pago*, Usuario*);
        ~Reserva();


        void setIdReserva(int);
        void setUsuario(Usuario*);
        void setPago(Pago*);

        Pago* getPago();
        Usuario* getUsuario();
        int getIdReserva();


};

#endif