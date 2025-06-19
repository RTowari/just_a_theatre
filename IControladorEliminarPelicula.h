#ifndef ICONTROLADORELIMINARPELUCLA
#define ICONTROLADORELIMINARPELUCLA

#include <string>

using namespace std;

class IControladorEliminarPelicula{

    public:
        virtual vector<DtPelicula> listarPeliculas()=0;
        virtual void eliminarPelicula(string titulo)=0;

};




#endif