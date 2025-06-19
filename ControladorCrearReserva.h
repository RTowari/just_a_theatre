#ifndef CONTROLADORCREARRESERVA
#define CONTROLADORCREARRESERVA

#include <string>
#include <list>
#include <set>
#include <vector>

#include "IControladorCrearReserva.h"
#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "Pago.h"

using namespace std;

class ControladorCrearReserva: public IControladorCrearReserva {
    private:
        string titulo;
        int IdC;
        Pago* pago = nullptr;  // inicializado en nullptr para seguridad
        float descuento;
        int totalDeAsientos;
    public:
        std::list<std::string> listarPeliculas();
        DtPelicula elegirDtPelicula();
        std::list<DtCine> listarCines();
        list<DtSala> listarFuncionesDeCine();
        float consultarDescuento(string financiera);
        
        void setTitulo(string);
        string getTitulo();

        void setIdC(int);
        int getIdC();

        void setTotalDeAsientos(int);

        //para procesar el pago de la persona
        void setDescuento(float);
        float setPagoCredito(string);
        float setPagoDebito(string);
        void confirmarReserva(int, int);

};

#endif