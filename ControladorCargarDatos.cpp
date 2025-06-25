#include "ControladorCargarDatos.h"

#include "ManejadorUsuario.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "ManejadorPelicula.h"
#include "ManejadorSala.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "Cine.h"
#include "Sala.h"
#include "Funcion.h"

#include "DtDireccion.h"
#include "DtHorario.h"
#include "DtFecha.h"

#include <vector>
#include <string>

using namespace std;

void ControladorCargarDatos::cargarDatos(){
    registrarUsuario("Gabriel", "urlMontania", "1");
    registrarUsuario("Jose", "urlGato", "2");
    registrarUsuario("Nando", "urlPerro", "3");
    registrarUsuario("Mauricio", "urlCasa", "4");

    registrarPelicula("The_Lost_City", "An_adventurer_gets_lost_in_an_ancient_jungle", 4.5, "urlMontania");
    registrarPelicula("Robot_Reckoning", "A_future_where_robots_rebel_against_humans", 4.8, "urlRobot");
    registrarPelicula("Whispers_of_Stone", "A_cursed_village_and_a_mysterious_statue", 3.9, "urlEstatua");
    registrarPelicula("Blood_Oath", "Vampires_and_hunters_strike_a_terrifying_truce", 4.2, "urlSangre");
    registrarPelicula("Echoes_of_Tomorrow", "Time_travel_goes_wrong_and_merges_realities", 4.7, "urlReloj");
    
    DtDireccion* direccion = new DtDireccion("Garzon", 1000);
    registrarCine(*direccion);
    direccion = new DtDireccion("Millan", 1001);
    registrarCine(*direccion);
    direccion = new DtDireccion("Colonia", 1002);
    registrarCine(*direccion);
    direccion = new DtDireccion("Rivera", 1003);
    registrarCine(*direccion);
    direccion = new DtDireccion("Paraguay", 1004);
    registrarCine(*direccion);
    direccion = new DtDireccion("Agraciada", 1005);
    registrarCine(*direccion);

    DtFecha* fecha = new DtFecha(10, 25, 2026);
    DtHorario* horario = new DtHorario(30, 13, 14, 30);
    registrarFuncion(1, "Blood_Oath", 1, *fecha, *horario);

    fecha = new DtFecha(10, 26, 2026);
    horario = new DtHorario(30, 14, 15, 30);
    registrarFuncion(1, "Blood_Oath", 1, *fecha, *horario);

    fecha = new DtFecha(10, 27, 2026);
    horario = new DtHorario(30, 15, 16, 30);
    registrarFuncion(2, "Echoes_of_Tomorrow", 6, *fecha, *horario);

    fecha = new DtFecha(10, 28, 2026);
    horario = new DtHorario(30, 16, 17, 30);
    registrarFuncion(2, "Echoes_of_Tomorrow", 6, *fecha, *horario);
 
}

void ControladorCargarDatos::registrarUsuario(string nicknane, string url, string constrasenia){
    Usuario* usuario = new Usuario(nicknane, constrasenia, url);
    ManejadorUsuario::getInstancia()->agregarUsuario(usuario);
}

void ControladorCargarDatos::registrarPelicula(string titulo, string sinopsis, float puntajePromedio, string poster){
    Pelicula* pelicula = new Pelicula(titulo, sinopsis, puntajePromedio, poster);
    ManejadorPelicula::getInstancia()->agregarPelicula(pelicula);
}

void ControladorCargarDatos::registrarCine(DtDireccion direccion){
   
    ManejadorCine* manejadorC = ManejadorCine::getInstancia();
    
    Cine* cine = new Cine(manejadorC->getSiguienteIdCine(), direccion);
    manejadorC->darDeAltaCine(cine);

    // Ahora creo salas y las añado al manejador usando el int que solo es accesible y no seteable
    int capacidad = 5;
    for (int i=0; i < capacidad; i++) {
        Sala* nuevaSala = new Sala(ManejadorSala::getInstancia()->getTopeSalas(), capacidad);
        
        ManejadorSala* manejadorS = ManejadorSala::getInstancia();
        

        manejadorS->agregarSala(nuevaSala);
        
        cine->agregarSala(nuevaSala); // por cada iteracion añado la sala al cine
    } 
}

void ControladorCargarDatos::registrarFuncion(int IdC, string titulo, int IdS, DtFecha fecha, DtHorario horario){
    ManejadorCine* mCine = ManejadorCine::getInstancia();
    ManejadorFuncion* mFuncion = ManejadorFuncion::getInstancia();
    ManejadorPelicula* mPelicula = ManejadorPelicula::getInstancia();

    // creo la funcion sin pelicula
    int id = mFuncion->generarNuevoId();
    Funcion* funcion = new Funcion(id, fecha, horario);

    // le seteo la pelicula a la funciomn y al cine
    funcion->agregarPelicula(mPelicula->buscarPelicula(titulo));
    mCine->buscarCine(IdC)->agregarPelicula(mPelicula->buscarPelicula(titulo));

    // agrego la funcion a la sala
    mCine->buscarCine(IdC)->obtenerSalaPorId(IdS)->agregarFuncion(funcion);

    // agrego la funcion al menejador
    mFuncion->agregarFuncion(funcion);

} 

