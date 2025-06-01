#ifndef CONTROLADORSESION
#define CONTROLADORSESION

#include <string>
#include "IControladorSesion.h"

using namespace std;

class ControladorSesion: public IControladorSesion{
    public:
        bool iniciarSesion(string nickname, string contrasenia);
        void cerrarSesion();
};

#endif