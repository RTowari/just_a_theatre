#ifndef CONTROLADORRELOJLOCAL_H
#define CONTROLADORRELOJLOCAL_H

#include "IControladorRelojLocal.h"

#include <list>

class ControladorRelojLocal : public IControladorRelojLocal {
    public:
        void modificarFechaLocal(int anio, int mes, int dia, int hora, int minuto);
        std::list<int> getFechaLocal();
};

#endif