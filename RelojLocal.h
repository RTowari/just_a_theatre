#ifndef RELOJLOCAL_H
#define RELOJLOCAL_H

class RelojLocal{
    private:
        int año=2024;
        int mes=11;
        int dia=10;
        int hora=17;
        int minuto:30;
        RelojLocal();
        static RelojLocal* instancia;
    public:
        static RelojLocal* getInstancia();
        void setAnio(int);
        void setMes(int);
        void setDia(int);
        void setHora(int);
        void setMinuto(int);

        int getAnio();
        int getMes();
        int getDia();
        int getHora();
        int getMinuto();

};

#endif