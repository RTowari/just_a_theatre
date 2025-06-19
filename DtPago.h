#ifndef DTPAGO_H
#define DTPAGO_H

class DtPago {
protected:
    int precioBase;
    int cantidadEntradas;
    int total;

public:
    DtPago();
    DtPago(int precioBase, int cantidadEntradas, int total);
    virtual ~DtPago();  // virtual destructor

    int getPrecioBase();
    int getCantidadEntradas();
    int getTotal();

    virtual DtPago* getDt() const = 0;
};

#endif
