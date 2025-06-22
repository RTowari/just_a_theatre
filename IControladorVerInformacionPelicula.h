#ifndef ICONTROLADORVERINFORMACIONPELICULA_H
#define ICONTROLADORVERINFORMACIONPELICULA_H

#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"

#include <string>
#include <list>

class IControladorVerInformacionPelicula{
    public:
        virtual void setTitulo(std::string)=0;
        virtual void setIdC(int)=0;

        virtual DtPelicula elegirDtPelicula()=0;
        virtual std::list<DtCine> listarCines()=0;
        virtual std::list<DtSala> listarFuncionesDeCine()=0;
};


#endif