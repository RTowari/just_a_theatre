#ifndef FUNCION_H
#define FUNCION_H

#include <list>

#include "DtFecha.h"
#include "DtHorario.h"
#include "DtFuncion.h"
#include "Reserva.h"
#include "Pelicula.h"
#include "Pago.h"

using namespace std;

class Funcion{

    private:
        int id;
        DtFecha fecha;
        DtHorario horario;
        int topeReserva=1; // sirva para saber cuantas reservas tengo. Por cada nueva reserva, hago un delete
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
        int getTopeReserva(); // esto no tiene setter. el setter aumenta cuando se agrega una reserva
        DtFecha getFecha();
        DtHorario getHorario();

        Pelicula* getPelicula();            //para cu eliminarPelicula
        string getPeliculaTitulo();         //para cu eliminarPelicula

        void agregarReserva(Reserva*);
        list<Reserva*> getReservas();

        void agregarPelicula(Pelicula*);    //para cu eliminarPelicula
        void eliminarPelicula();            //para cu eliminarPelicula

        //cu CrearReserva
        bool existePelicula(string titulo); 
        DtFuncion getDt();
        
};

#endif