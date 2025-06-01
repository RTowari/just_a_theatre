#ifndef ICONTROLADORSESION
#define ICONTROLADORSESION
#include<list>
#include<string>

using namespace std;

class IControlador{
    public:      
       virtual void iniciarSesion(string nickname, string contrasenia)=0;
       virtual void cerrarSesion()=0;
};

#endif
