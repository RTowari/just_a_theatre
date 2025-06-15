#ifndef COMENTARIO
#define COMENTARIO
#include <string>

#include "DtComentario.h"

using namespace std;

class Comentario{
    private:
        string texto;
        Comentario* comentarioRespondido;
    public:
        Comentario();
        Comentario(string);
        ~Comentario();
        
        void setTexto(string);
        void setComentarioRespondido(Comentario*);

        string getTexto();
        Comentario* getComentarioRespondido();

        DtComentario getDt();    

};


#endif