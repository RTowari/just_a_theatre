#ifndef ICONTROLADORALTAUSUARIO
#define ICONTROLADORALTAUSUARIO

using namespace std;

class IControladorAltaUsuario{
    public:
        virtual void altaUsuario(string nickname, string pass, string urlFoto)=0;
};



#endif