#ifndef DT_INFO_PELICULA
#define DT_INFO_PELICULA

#include <string>
#include <vector>
#include "DtPelicula.h"   
#include "DtComentario.h" 
#include "DtPuntaje.h"    

using namespace std;

class DtInfoPelicula {
private:
    DtPelicula* infoPelicula;
    int cantidadUsuariosPuntuaron;
    vector<DtComentario> comentarios; 
    vector<DtPuntaje> puntajes;      

public:
    DtInfoPelicula(DtPelicula* info, int cantUsuarios, vector<DtComentario> comentarios, vector<DtPuntaje> puntajes);
    ~DtInfoPelicula(); 

    //  getter para acceder a la información
    DtPelicula* getInfoBasica();
    int getCantidadUsuariosPuntuaron();
    vector<DtComentario>& getComentarios(); 
    vector<DtPuntaje>& getPuntajes();       
};

#endif
