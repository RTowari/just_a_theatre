#ifndef USUARIO
#define USUARIO

#include <iostream>

using namespace std;

class Usuario{
    private:
        string nickname;
        string contrasenia;
        string urlFoto;
    public:
        Usuario();
        Usuario(string, string, string);
        
        string getNickname();
        void setNickname(string nickname);

        string getContrasenia();
        void setContrasenia(string contrasenia);

        string getUrlFoto();
        void setUrlFoto();

        ~Usuario();
};

#endif