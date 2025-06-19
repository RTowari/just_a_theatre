#ifndef PAGO_H
#define PAGO_H

#include "PrecioBase.h"
#include "DtPago.h"

#include <string>

using namespace std;

class Pago {
    protected:
        const int precioBase;
        int cantidadEntradas;
        int total;

    public:
        Pago(int precioBase = PRECIO_BASE, int cantidadEntradas = 0);  // Now includes cantidadEntradas
        virtual int procesarPago() = 0;
        int getPrecioBase();
        int getTotal();
        virtual DtPago* getDt()= 0;
        virtual ~Pago();
};

#endif