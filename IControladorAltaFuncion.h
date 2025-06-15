#ifndef ICONTROLADORALTAFUNCION_H
#define ICONTROLADORALTAFUNCION_H

#include <string>
#include <list>
#include "DtCine.h"
#include "DtSala.h"
#include "DtHorario.h"
#include "DtFecha.h"


using namespace std;

class IControladorAltaFuncion{
    public:
        virtual void setTi(string Ti)=0;
        virtual string getTi()=0;

        virtual void setIdC(int IdC)=0;
        virtual int getIdC()=0;
        
        virtual void setIdS(int IdS)=0;
        virtual int getIdS()=0;
        
        virtual void setDtHorario(DtHorario dtHorario)=0;
        virtual DtHorario getDtHorario()=0;

        virtual void setDtFecha(DtFecha dtFecha)=0;
        virtual DtFecha getDtFecha()=0;
        
        virtual list<DtCine> listarCines() = 0; // devuelve un set de Dt cines
        virtual list<DtSala> listarSalasDeCine()=0;
        virtual void agregarFuncionASala()=0;
};


#endif