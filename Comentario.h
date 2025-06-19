#ifndef COMENTARIO
#define COMENTARIO
#include <string>

#include "DtComentario.h"
#include "Usuario.h"

using namespace std;

class Comentario{
    private:
        string texto;
        Usuario* usuario;   
        Comentario* comentarioRespondido;
    public:
        Comentario();
        Comentario(string, Usuario*);
        Comentario(string, Usuario*, Comentario*);
        ~Comentario();
        
        void setTexto(string);
        void setComentarioRespondido(Comentario*);
        void setUsuario(Usuario* );

        string getTexto();
        Comentario* getComentarioRespondido();
        Usuario* getUsuario();

        DtComentario getDt();    

};


#endif