#ifndef COMENTARIO
#define COMENTARIO
#include <string>

#include "DtComentario.h"
#include "Usuario.h"

using namespace std;

class Comentario{
    private:
        string texto;
        Comentario* comentarioRespondido;
        Usuario* usuario;
    public:
        Comentario();
        Comentario(string);
        ~Comentario();
        
        void setTexto(string);
        void setComentarioRespondido(Comentario*);
        void setUsuario(Usuario*);

        string getTexto();
        Comentario* getComentarioRespondido();
        Usuario* getUsuario();

        DtComentario getDt();    

};


#endif