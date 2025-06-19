#ifndef ICONTROLADORVERRESERVA_H
#define ICONTROLADORVERRESERVA_H

#include <string>
#include <iostream>
#include <list>

#include "DtFuncion.h"

class IControladorVerReserva{
    public:
        virtual std::list<DtFuncion> listarReservas(std::string titulo)=0;
};
#endif