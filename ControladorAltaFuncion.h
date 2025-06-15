#ifndef CONTROLADORALTAFUNCION_H
#define CONTROLADORALTAFUNCION_h

#include "IControladorAltaFuncion.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"

#include <string>
#include <list>

using namespace std;

class ControladorAltaFuncion: public IControladorAltaFuncion {
    private:
        string Ti;
        int IdC;
        int IdS;
        DtFecha dtFecha;
        DtHorario dtHorario;
    public:
        // estos dos int se setean en el front segun el usuario elige peli y cine
        void setTi(string Ti);
        string getTi();

        void setIdC(int IdC);
        int getIdC();

        void setIdS(int IdS);
        int getIdS();

        void setDtFecha(DtFecha dtFecha);
        DtFecha getDtFecha();

        void setDtHorario(DtHorario dtHorario);
        DtHorario getDtHorario();

        list<DtCine> listarCines();
        list<DtSala> listarSalasDeCine();

        void agregarFuncionASala();
};


#endif