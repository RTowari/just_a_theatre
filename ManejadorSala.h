#ifndef MANEJADOR_SALA_H
#define MANEJADOR_SALA_H

#include "Sala.h"
#include <list>

using namespace std;

class ManejadorSala {
    private:
        static ManejadorSala* instancia;
        list<Sala*> salas;
        int topeSalas=1;
        ManejadorSala();  // private constructor for singleton

    public:
        static ManejadorSala* getInstancia();

        list<Sala*> getSala();
        Sala* buscarSalas(int id);
        void agregarSala(Sala* sala);
        bool existeSala(int id);
        void eliminarSala(int id);

        int getTopeSalas();

        ~ManejadorSala();
};

#endif
