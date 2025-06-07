#ifndef ICONTROLADORALTACINE
#define ICONTROLADORALTACINE

#include <string>
using namespace std;

class IControladorAltaCine{
    public:
        virtual void altaCine(string titulo, string sinopsis, float PuntajePromedio, string urlFoto)=0;
};

#endif