#ifndef DTRESERVA_H
#define DTRESERVA_H

using namespace std;

class DtReserva {
    private:
        int IdReserva;
        int cantEntradas;
        float costo;
    
        public:
            DtReserva();
            DtReserva(int, int, float);

            int getIdReserva();
            int getCosto();
            int getCantEntradas();

            ~DtReserva();
};

#endif