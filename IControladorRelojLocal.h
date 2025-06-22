#ifndef ICONTROLADORRELOJLOCAL_H
#define ICONTROLADORRELOJLOCAL_H


#include <list>

class IControladorRelojLocal {
    public:
        virtual void modificarFechaLocal(int anio, int mes, int dia, int hora, int minuto)=0;
        virtual std::list<int> getFechaLocal()=0;
};


#endif