#ifndef DTFECHA
#define DTFECHA

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        DtFecha();
        DtFecha(int,int,int);

        void setDia(int);
        void setMes(int);
        void setAnio(int);

        int getDia();
        int getMes();
        int getAnio();

};


#endif