#ifndef ICONTROLADORCREARRESERVA_H
#define ICONTROLADORCREARRESERVA_H

#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"

#include <string>
#include <list>
#include <vector>
#include <iomanip>

using namespace std;

class IControladorCrearReserva{
    public:
        virtual std::list<std::string> listarPeliculas()=0;
        virtual DtPelicula elegirDtPelicula()=0;
        virtual list<DtCine> listarCines()=0;
        virtual list<DtSala> listarFuncionesDeCine()=0;
        virtual float consultarDescuento(string)=0;

        virtual void setTitulo(string)=0;
        virtual string getTitulo()=0;

        virtual void setIdC(int)=0;
        virtual int getIdC()=0;

        virtual void setDescuento(float)=0;
        virtual float setPagoCredito(string)=0;
        virtual float setPagoDebito(string)=0;
        virtual void setTotalDeAsientos(int)=0;
        virtual void confirmarReserva(int, int)=0;

};

#endif


