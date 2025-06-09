#ifndef ICONTROLADORCREARRESERVA_H
#define ICONTROLADORCREARRESERVA_H

#include "DtPelicula.h"
#include "DtCine.h"

#include <string>
#include <list>
#include <vector>

using namespace std;

class IControladorCrearReserva{
    public:
        virtual std::list<std::string> listarPeliculas()=0;
        virtual DtPelicula elegirDtPelicula(std::string titulo)=0;
        //virtual std::vector<DtCine> listarCines(string titulo)=0;
};

#endif

