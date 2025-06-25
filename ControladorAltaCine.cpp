#include "ControladorAltaCine.h"
#include "ManejadorCine.h"
#include "ManejadorSala.h"
#include "Cine.h"
#include "DtCine.h"
#include "DtDireccion.h"
#include <iostream>             
#include <stdexcept>            
#include <vector>              

using namespace std;


void ControladorAltaCine::altaCine(const DtCine& dtCine, const std::vector<int>& capacidadesSalas){
    Cine* nuevoCine = nullptr;
    

    // genero un cine usando los datos que me llegaron desde el front
    ManejadorCine* mC = ManejadorCine::getInstancia();
    int idCine = mC->getSiguienteIdCine();
    nuevoCine = new Cine(idCine, dtCine.getDireccion());
        
    // Ahora creo salas y las añado al manejador usando el int que solo es accesible y no seteable
    for (int capacidad : capacidadesSalas) {
        
        Sala* nuevaSala = new Sala(ManejadorSala::getInstancia()->getTopeSalas(), capacidad);
        
        ManejadorSala::getInstancia()->agregarSala(nuevaSala);
        
        nuevoCine->agregarSala(nuevaSala); // por cada iteracion añado la sala al cine
    }

        
    mC->darDeAltaCine(nuevoCine);
  

}