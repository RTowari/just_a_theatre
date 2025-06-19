#include "ControladorVerReserva.h"
#include "ManejadorFuncion.h"
#include "Funcion.h"

#include "DtPago.h"
#include "DtCredito.h"
#include "DtDebito.h"

#include <list>
#include <string>

std::list<DtFuncion> ControladorVerReserva::listarReservas(std::string titulo) {


    // dado el titulo de una pelicuula, itero a traves de cada funcion buscado el titulo que quiero
    // si la fuuncion tiene el titulo, me la quedo
    list<Funcion*> funcionesDeTitulo = ManejadorFuncion::getInstancia()->getFuncionesPorTitulo(titulo);

    
    // ahora itero
    
    std::list<DtFuncion> dtFunciones;
    for (Funcion* funcion : funcionesDeTitulo) {
        DtFuncion dtFuncion = funcion->getDt();
        dtFunciones.push_back(dtFuncion);
    }

    return dtFunciones;
    

}