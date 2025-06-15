#ifndef CONTROLADORCOMENTARPELICULA
#define CONTROLADORCOMENTARPELICULA

#include "IControladorComentarPelicula.h"
#include "DtComentario.h"


class ControladorComentarPelicula : public IControladorComentarPelicula{

    public:
        vector<DtPelicula> listarPeliculas();
        vector<DtComentario> listarComentarios(string);
        void comentarPelicula(string, string, int);
};


#endif