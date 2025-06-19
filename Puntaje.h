#ifndef PUNTAJE
#define PUNTAJE
#include <string>

#include "DtPuntaje.h"
#include "Usuario.h"
using namespace std;

class Puntaje{
    private:
        int puntaje;
        Usuario* usuario;
    public:
        Puntaje();
        Puntaje(int, Usuario*);
        ~Puntaje();
        
        void setPuntaje(int);
        int getPuntaje();

        void setUsuario(Usuario* );
        Usuario* getUsuario();

};

#endif
