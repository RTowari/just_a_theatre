#include "Sala.h"
#include "DtSala.h"
#include "RelojLocal.h"

#include "iostream"

Sala::Sala(){}
Sala::Sala(int id,int capacidad){
	this->id=id;
	this->capacidad=capacidad;
}

// no se permite setear la id manualmente porque lo hace el controlador cine
int Sala::getId() const{
	return this->id;
}


int Sala::getCapacidad() const{
	return this->capacidad;
}
void Sala::setCapacidad(int capacidad){
	this->capacidad=capacidad;
}


//para cu eliminarPelicula
// esta funcion hace que la sala olvide la funcion. la funcion sigue existiendo y hay que eliminarla usando el manejador
void Sala::eliminarPeliFuncion(string titulo) {
    for (map<int, Funcion*>::iterator it = funciones.begin(); it != funciones.end(); ) {
        Funcion* funcion = it->second;
        if (funcion != nullptr && funcion->getPelicula()->getTitulo() == titulo) {
            it = funciones.erase(it);  // borrar entrada y actualizar iterador
            capacidad++; // aumenta la capacidad de la sala porque la funcion fue eliminada
        } else {
            ++it;  // avanzar iterador normalmente
        }
    }


}

//para cu altaFuncion
DtSala Sala::getDt(){
    return DtSala(this->id, this->capacidad);
}
void Sala::agregarFuncion(Funcion* funcion){

    int id = funcion->getId();  
    funciones[id] = funcion;
      
}

// para cu crearReserva
map<int,Funcion*> Sala::obtenerFunciones(){
	return this->funciones;
}
DtSala Sala::obtenerSalaPorPelicula(string titulo){
    //creo mi dt sala de la sala actual
    DtSala dtSala(this->id, this->capacidad);
    
    for (map<int, Funcion*>::iterator it = funciones.begin(); it != funciones.end(); ++it) {
        
        Funcion* funcion = it->second;
        //si tengo una funcion con la pelicula que busco la pongo en mi dt sala
        if(funcion != nullptr && funcion->existePelicula(titulo)){
            DtFuncion dtFuncion = funcion->getDt();
            dtSala.agregarDtFuncion(dtFuncion);
        }
    }
    return dtSala; // despues de agregar a mi sala las funciones con funciones que tienen la pelicula que busco, devuelvo la sala
}
DtSala Sala::obtenerSalaPorPeliculaYFecha(string titulo){

    RelojLocal* reloj = RelojLocal::getInstancia();
    int ho = reloj->getHora();
    int mi = reloj->getMinuto();
    int dia = reloj->getDia();
    int mes = reloj->getMes(); 
    int año = reloj->getAnio();
    
    //creo mi dt sala de la sala actual
    DtSala dtSala(this->id, this->capacidad);
    
    for (map<int, Funcion*>::iterator it = funciones.begin(); it != funciones.end(); ++it) {
        Funcion* funcion = it->second;
        
        if (funcion == nullptr || !funcion->existePelicula(titulo))
            continue;

        DtFecha fecha = funcion->getFecha();
        DtHorario horario = funcion->getHorario();

        bool fechaValida =
            (fecha.getAnio() > año) ||
            (fecha.getAnio() == año && fecha.getMes() > mes) ||
            (fecha.getAnio() == año && fecha.getMes() == mes && fecha.getDia() > dia) ||
            (fecha.getAnio() == año && fecha.getMes() == mes && fecha.getDia() == dia &&
            (horario.getHoraComienzo() > ho ||
            (horario.getHoraComienzo() == ho && horario.getMinutoComienzo() >= mi)));

        if (fechaValida) {
            DtFuncion dtFuncion = funcion->getDt();
            dtSala.agregarDtFuncion(dtFuncion);
        }
    }
    return dtSala;
}

Sala::~Sala() {}