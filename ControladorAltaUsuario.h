#ifndef CONTROLADORALTAUSUARIO
#define CONTROLADORALTAUSUARIO

#include<string>

#include "IControladorAltaUsuario.h"

using namespace std;

class ControladorAltaUsuario: public IControladorAltaUsuario {
    public:
        void altaUsuario(string nickname, string contrasenia, string urlFoto);

};


#endif