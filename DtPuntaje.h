#ifndef DT_PUNTAJE
#define DT_PUNTAJE

#include <string>
#include "DtUsuario.h"

using namespace std;

class DtPuntaje{
    
    private:
        int puntaje;
        DtUsuario* usuario;

    public:
        DtPuntaje();
        DtPuntaje(int, DtUsuario*);
        ~DtPuntaje();

        int getPuntaje();
        DtUsuario* getUsuario();

};

#endif