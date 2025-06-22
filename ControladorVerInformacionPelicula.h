#ifndef CONTROLADORVERINFORMACIONPELICULA_H
#define CONTROLADORVERINFORMACIONPELICULA_H

#include "IControladorVerInformacionPelicula.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"

#include <string>

class ControladorVerInformacionPelicula : public IControladorVerInformacionPelicula {
    private:
        std::string titulo;
        int IdC;
    public:
        void setTitulo(std::string);
        std::string getTitulo();

        void setIdC(int);
        int getIdC();

        DtPelicula elegirDtPelicula();
        list<DtCine> listarCines();
        list<DtSala> listarFuncionesDeCine();
};


#endif