#ifndef ICONTROLADORCOMENTARPELICULA
#define ICONTROLADORCOMENTARPELICULA

#include <string>
#include <vector>

#include "DtPelicula.h"
#include "DtComentario.h"

using namespace std;

class IControladorComentarPelicula{

    public:
        virtual vector<DtPelicula> listarPeliculas()=0;
        virtual vector<DtComentario> listarComentarios(string)=0;
        virtual void comentarPelicula(string, string, int)=0;
};


#endif