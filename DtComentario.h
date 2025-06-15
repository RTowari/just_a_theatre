#ifndef DT_COMENTARIO
#define DT_COMENTARIO

#include <string>
using namespace std;

class DtComentario{
    
    private:
        string texto;
        string comentarioRespondido;

    public:
        DtComentario();
        DtComentario(string, string);
        ~DtComentario();

        string getTexto();
        string getComentarioRespondido();

};

#endif
