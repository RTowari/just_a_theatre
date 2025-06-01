#ifndef ICONTROLADORSESION
#define ICONTROLADORSESION

#include <string>
#include "DtSesion.h"

using namespace std;

class IControladorSesion{
    public:
        virtual bool iniciarSesion(string nickname, string contrasenia)=0;
        virtual void cerrarSesion()=0;
};
#endif
