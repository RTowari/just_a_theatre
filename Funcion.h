#ifndef FUNCION
#define FUNCION

#include "DtFecha.h"
#include "DtHorario.h"

class Funcion{

    private:
        int id;
        DtFecha* fecha;
        DtHorario* horario;
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
};

#endif