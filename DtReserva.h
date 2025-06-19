#ifndef DTRESERVA_H
#define DTRESERVA_H

#include "DtPago.h"

class DtReserva {
private:
    int idReserva;
    DtPago* pago;

public:
    DtReserva();
    DtReserva(int idReserva, DtPago* pago);
    DtReserva(const DtReserva& other);
    ~DtReserva();

    DtReserva& operator=(const DtReserva& other);

    int getIdReserva();
    DtPago* getPago();
};

#endif
