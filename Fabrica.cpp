#include "Fabrica.h"
#include "ControladorSesion.h"
#include "ControladorAltaUsuario.h"
#include "ControladorAltaPelicula.h"
#include "ControladorCrearReserva.h"
#include "ControladorAltaCine.h"
#include "ControladorEliminarPelicula.h"
#include "ControladorComentarPelicula.h"
#include "ControladorPuntuarPelicula.h"
#include "ControladorAltaFuncion.h"
#include "ControladorVerReserva.h"
#include "ControladorVerInformacionPelicula.h"
#include "ControladorVerComentariosyPuntajesdePelicula.h"
#include "ControladorRelojLocal.h"
#include "ControladorCargarDatos.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL) 
        instancia = new Fabrica();
    return instancia;
}

IControladorSesion* Fabrica::getIControladorSesion(){
    return new ControladorSesion();    
}

IControladorAltaUsuario* Fabrica::getIControladorAltaUsuario(){
    return new ControladorAltaUsuario();    
}

IControladorAltaPelicula* Fabrica::getIControladorAltaPelicula(){
    return new ControladorAltaPelicula();    
}

IControladorCrearReserva* Fabrica::getIControladorCrearReserva(){
    return new ControladorCrearReserva();
}

IControladorAltaCine* Fabrica::getIControladorAltaCine(){
    return new ControladorAltaCine();
}

IControladorEliminarPelicula* Fabrica::getIControladorEliminarPelicula(){
    return new ControladorEliminarPelicula();
}

IControladorComentarPelicula* Fabrica::getIControladorComentarPelicula(){
    return new ControladorComentarPelicula();
}

IControladorPuntuarPelicula* Fabrica::getIControladorPuntuarPelicula(){
    return new ControladorPuntuarPelicula();
}

IControladorAltaFuncion* Fabrica::getIControladorAltaFuncion(){
    return new ControladorAltaFuncion();
}

IControladorVerReserva* Fabrica::getIControladorVerReserva(){
    return new ControladorVerReserva();
}

IControladorVerInformacionPelicula* Fabrica::getIControladorVerInformacionPelicula(){
    return new ControladorVerInformacionPelicula();
}

IControladorVerComentariosyPuntajesdePelicula* Fabrica::getIControladorVerComentariosyPuntajesdePelicula(){
    return new ControladorVerComentariosyPuntajesdePelicula();
}

IControladorRelojLocal* Fabrica::getIControladorRelojLocal(){
    return new ControladorRelojLocal();
}

IControladorCargarDatos* Fabrica::getIControladorCargarDatos(){
    return new ControladorCargarDatos();
}



Fabrica::~Fabrica(){}

