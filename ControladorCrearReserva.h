#ifndef CONTROLADORCREARRESERVA
#define CONTROLADORCREARRESERVA

#include <string>
#include <list>
#include <set>
#include <vector>

#include "IControladorCrearReserva.h"
#include "DtPelicula.h"
#include "DtCine.h"

using namespace std;

class ControladorCrearReserva: public IControladorCrearReserva {
    public:
        std::list<std::string> listarPeliculas();
        DtPelicula elegirDtPelicula(string);
        //std::vector<DtCine> listarCines(string);
};

#endif