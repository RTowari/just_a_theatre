#ifndef CONTROLADORSESION
#define CONTROLADORSESION

#include <string>
#include "iControladorSesion.h"

using namespace std;

class ControladorSesion: public IControladorSesion{
    public:
        bool iniciarSesion(string nickname, string contrasenia);
        //void cerrarSesion();
};

#endif