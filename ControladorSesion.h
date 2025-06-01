#ifndef CONTROLADORSESION
#define CONTROLADORSESION
#include "IControladorSesion.h"
#include <string>
#include <list>

using namespace std;

class Controlador: public IControladorSesion{
    public:
        void iniciarSesion(string nickname, string contrasenia);
        void cerrarSesion();

};
#endif
