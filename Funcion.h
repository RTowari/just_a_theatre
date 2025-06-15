#ifndef FUNCION_H
#define FUNCION_H

#include <list>

#include "DtFecha.h"
#include "DtHorario.h"
#include "Reserva.h"
#include "Pelicula.h"

using namespace std;

class Funcion{

    private:
        int id;
        DtFecha fecha;
        DtHorario horario;
        list<Reserva*> reservas;
        Pelicula* pelicula;                 //para cu eliminarPelicula
    public:
        Funcion();
        Funcion(int,DtFecha,DtHorario);
        ~Funcion();

        void setId(int);
        void setFecha(DtFecha);
        void setHorario(DtHorario);

        int getId();
        DtFecha getFecha();
        DtHorario getHorario();

        Pelicula* getPelicula();            //para cu eliminarPelicula

        void agregarReserva(Reserva*);
        list<Reserva*> getReservas();

        void agregarPelicula(Pelicula*);    //para cu eliminarPelicula
        void eliminarPelicula();            //para cu eliminarPelicula
};

#endif