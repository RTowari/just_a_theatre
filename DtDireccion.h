#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>

using namespace std;

class DtDireccion{
    private:
        string calle;
        int numero;
    public:
        DtDireccion();
        DtDireccion(string,int);

        void setCalle(string);
        void setNumero(int);

        string getCalle() const;
        int getNumero() const;

        ~DtDireccion();
};

#endif
