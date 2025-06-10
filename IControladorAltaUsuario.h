#ifndef ICONTROLADORALTAUSUARIO
#define ICONTROLADORALTAUSUARIO

#include <string>
#include "DtUsuario.h"

using namespace std;

class IControladorAltaUsuario{
    public:
        virtual void altaUsuario(string nickname, string pass, string urlFoto)=0;
};



#endif