#ifndef ICONTROLADORSESION
#define ICONTROLADORSESION

#include <string>

using namespace std;

class IControladorSesion{
    public:
        virtual void iniciarSesion(string nickname, string contrasenia)=0;
        //virtual void cerrarSesion()=0;
};
#endif
