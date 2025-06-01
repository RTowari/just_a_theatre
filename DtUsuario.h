#ifndef DTUSUARIO
#define DTUSUARIO

#include <iostream>

using namespace std;

class DtUsuario{
    private:
        string nickname;
        string contrasenia;
        string urlFoto;
    public:
        DtUsuario();
        DtUsuario(string, string, string);
        string getNickname();
        string getContrasenia();
        string getUrlFoto();
        ~DtUsuario();
};
#endif