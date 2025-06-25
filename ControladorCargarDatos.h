#ifndef CONTROLADORCARGARDATOS_H
#define CONTROLADORCARGARDATOS_H

#include "IControladorCargarDatos.h"
#include "DtDireccion.h"
#include "DtHorario.h"
#include "DtFecha.h"

#include <string>


using namespace std;

class ControladorCargarDatos : public IControladorCargarDatos {
    void cargarDatos();
    void registrarUsuario(string nicknane, string url, string constrasenia);
    void registrarPelicula(string titulo, string sinopsis, float puntajePromedio, string poster);
    void registrarCine(DtDireccion direccion);
    void registrarFuncion(int IdC, string titulo, int IdS, DtFecha fecha, DtHorario horario);
};

#endif