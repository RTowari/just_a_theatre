#ifndef DTHORARIO
#define DTHORARIO

#include <string>

using namespace std;

class DtHorario{
    private:
        string horaComienzo;
        string horaFin;
    public:
        DtHorario();
        DtHorario(string,string);

        void setHoraComienzo(string);
        void setHoraFin(string);

        string getHoraComienzo();
        string getHoraFin();
};

#endif