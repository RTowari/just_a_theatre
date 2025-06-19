#include "ManejadorPelicula.h"
#include "ControladorCrearReserva.h"
#include "ManejadorFuncion.h"
#include "ManejadorCine.h"
#include "Sala.h"
#include "Sesion.h"

#include "DtPelicula.h"
#include "DtFuncion.h"
#include "DtCine.h"
#include "ManejadorFinanciera.h" // esto solo guarda las financieras y sus descuentos. no tiene ninguna importancia
#include "Credito.h"
#include "Debito.h"

#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::list<std::string> ControladorCrearReserva::listarPeliculas() {

    // Llamo al manejador y lo asigno a una variable
    ManejadorPelicula* manejadorP = ManejadorPelicula::getInstancia();

    // El manejador me devuelve una lista de pelicuulas
    std::list<Pelicula*> peliculas = manejadorP->getPeliculas();

    // Creo una lista de strings para almacenar los títulos
    std::list<std::string> titulos;

    // Itero sobre la lista de películas y extraigo los títulos
    for (Pelicula* pelicula : peliculas) {
        if (pelicula) {  // Asegurarse de que no sea nullptr
            titulos.push_back(pelicula->getTitulo()); 
        }
    }

    return titulos;

}

void ControladorCrearReserva::setTitulo(string titulo){
    this->titulo=titulo;
}
string ControladorCrearReserva::getTitulo(){
    return this->titulo;
}

void ControladorCrearReserva::setIdC(int IdC){
    this->IdC=IdC;
}
int ControladorCrearReserva::getIdC(){
    return this->IdC;
}


DtPelicula ControladorCrearReserva::elegirDtPelicula() {

    // Llamo al manejador para que me devuelva una pelicula dado un titulo
    Pelicula* pelicula = ManejadorPelicula::getInstancia()->buscarPelicula(this->getTitulo());

    // Convierto la pelicula en un DT
    DtPelicula dtPelicula = pelicula->getDt();

    return dtPelicula;
}

// Devuelve un set de cines segun una pelicula cuyo titulo paso en el nombre de la funcion
list<DtCine> ControladorCrearReserva::listarCines() {
    
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();

    // Me devuelven listas
    std::list<Cine*> cines = manejadorC->getCines();
   
    // busco todos los cines y por cada uno que contenga la pelicula que quiero, lo pongo en una lista
    list<DtCine> dtCines;
    for(Cine* cine : cines) {
        if(cine->existePelicula(this->getTitulo())){ // esto me devuelve un true si el cine tiene la pelicula.
            DtCine dtCine = cine->getDt();
            dtCines.push_back(dtCine);
        }
    }

    return dtCines;     
}

// devuelvo un set de funciones del cine que el usuario me paso
list<DtSala> ControladorCrearReserva::listarFuncionesDeCine(){
    // esto me devuelve el cine en el que voy a buscar las funciones con determinado id
    Cine* cine = ManejadorCine::getInstancia()->buscarCine(this->getIdC());

    // le pido a mi cine las funciones que me interesan en una determinada fecha
    list<DtSala> dtSalas = cine->obtenerSalasPorPeliculaYFecha(titulo);

    return dtSalas;
}

float ControladorCrearReserva::consultarDescuento(string financiera){
    return ManejadorFinanciera::getInstancia()->obtenerDescuento(financiera);
}

void ControladorCrearReserva::setDescuento(float descuento){
    this->descuento = descuento;
}

void ControladorCrearReserva::setTotalDeAsientos(int totalDeAsientos){
    this->totalDeAsientos=totalDeAsientos;
}

float ControladorCrearReserva::setPagoCredito(string entidad_financiera){
    // Libero el pago anterior si existía
    if (this->pago) {
        pago = nullptr;
    }

    // Creo un nuevo pago con credito, con el precioBase fijo de Pago (100), la financiera y el descuento
    this->pago = new Credito(entidad_financiera, descuento, totalDeAsientos);

    return this->pago->procesarPago();
}

float ControladorCrearReserva::setPagoDebito(string entidad_financiera) {
    if (this->pago) {
        pago = nullptr;
    }

    this->pago = new Debito(entidad_financiera, totalDeAsientos);  // Asumiendo Debito no tiene descuento

    return this->pago->procesarPago();
}  

// esto crea la reserva y la guarda en la array de reservas en la funcion que el usuario eligio
void ControladorCrearReserva::confirmarReserva(int funcionElegida, int salaElegida){

    if (this->pago == nullptr) {
        throw std::runtime_error("[ERROR CATASTROFICO] Esta funcion no se puede usar sin setear un pago en el controlador");
    }

    // me fijo si la funcion que el usuario pidio existe en las funciones
    bool funcionElegidaExiste = ManejadorFuncion::getInstancia()->existeFuncion(funcionElegida);
    
    if (!funcionElegidaExiste){
        throw std::runtime_error("[ERROR CATASTROFICO] Se esta intentado poner una reserva en una funcion que no existe");
    }

    // tengo que reducir el total de asientos de la sala en donde voy a crear mi reserva
    int salaCapacidad = ManejadorCine::getInstancia()->buscarCine(IdC)->obtenerSalaPorId(salaElegida)->getCapacidad();
    if(salaCapacidad > totalDeAsientos){
        throw std::runtime_error("[ERROR CATASTROFICO] Se intentaron comprar mas asientos de los que la sala permite");
    }
    else {
        int capacidadSalaActual = ManejadorCine::getInstancia()->buscarCine(IdC)->obtenerSalaPorId(salaElegida)->getCapacidad();
        capacidadSalaActual=capacidadSalaActual-totalDeAsientos;
        ManejadorCine::getInstancia()->buscarCine(IdC)->obtenerSalaPorId(salaElegida)->setCapacidad(totalDeAsientos);
    }

    // ahora creo mi reserva usando los datos que tengo y se lo paso a la funcion
    Reserva* nuevaReserva = new Reserva(ManejadorFuncion::getInstancia()->buscarFuncion(funcionElegida)->getTopeReserva(), this->pago, Sesion::getInstancia()->getUsuario());
    
    if (nuevaReserva == nullptr){
        throw std::runtime_error("[ERROR CATASTROFICO] La reserva esta vacia");
    }

    // ahora pongo la reserva en la funcion. como la sala ya conoce esta funcion (por pointer), no tengo que pasar por las salas
    ManejadorFuncion::getInstancia()->buscarFuncion(funcionElegida)->agregarReserva(nuevaReserva);

    



}

