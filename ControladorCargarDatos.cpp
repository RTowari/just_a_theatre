#include "ControladorCargarDatos.h"

#include "ManejadorUsuario.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "ManejadorPelicula.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "Cine.h"

#include "DtDireccion.h"

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
   
    vector<int> capacidadesSalas;
    capacidadesSalas.push_back(5);
    capacidadesSalas.push_back(5);
    capacidadesSalas.push_back(5);
    capacidadesSalas.push_back(5);
    capacidadesSalas.push_back(5);

    int id = ManejadorCine::getInstancia()->getSiguienteIdCine();
    Cine* cine = new Cine(id, direccion);
    ManejadorCine::getInstancia()->darDeAltaCine(cine, capacidadesSalas);
    
}

