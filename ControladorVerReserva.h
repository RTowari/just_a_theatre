#include <string>

#include "IControladorVerReserva.h"

class ControladorVerReserva : public IControladorVerReserva {
    public:
        std::list<DtFuncion> listarReservas(std::string titulo);
};