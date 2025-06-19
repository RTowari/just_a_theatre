#ifndef DTHORARIO
#define DTHORARIO

#include <string>

using namespace std;

class DtHorario{
    private:
        int mComienzo;
        int hComienzo;
        int mFin;
        int hFin;
    public:
        DtHorario();
        DtHorario(int, int, int, int);

        int getHoraComienzo();
        int getMinutoComienzo();

        int getHoraFin();
        int getMinutoFin();
};

#endif