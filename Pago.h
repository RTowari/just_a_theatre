#ifndef PAGO_H
#define PAGO_H

class Pago {
    protected:
        float montoBase;
    public:
        Pago();
        Pago(float montoBase);
        virtual float calcularMontoFinal() = 0;
        virtual ~Pago();
};
#endif