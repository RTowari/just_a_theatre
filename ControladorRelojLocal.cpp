#include "ControladorRelojLocal.h"
#include "RelojLocal.h"

#include <list>

void ControladorRelojLocal::modificarFechaLocal(int anio, int mes, int dia, int hora, int minuto){
    RelojLocal::getInstancia()->setAnio(anio);
    RelojLocal::getInstancia()->setMes(mes);
    RelojLocal::getInstancia()->setDia(dia);
    RelojLocal::getInstancia()->setHora(hora);
    RelojLocal::getInstancia()->setMinuto(minuto);
}

std::list<int> ControladorRelojLocal::getFechaLocal(){
    std::list<int> unidadesTiempo_own;
    unidadesTiempo_own.push_front(RelojLocal::getInstancia()->getAnio());
    unidadesTiempo_own.push_front(RelojLocal::getInstancia()->getMes());
    unidadesTiempo_own.push_front(RelojLocal::getInstancia()->getDia());
    unidadesTiempo_own.push_front(RelojLocal::getInstancia()->getHora());
    unidadesTiempo_own.push_front(RelojLocal::getInstancia()->getMinuto());

    return unidadesTiempo_own;

}

