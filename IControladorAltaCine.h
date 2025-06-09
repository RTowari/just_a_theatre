#ifndef ICONTROLADORALTACINE
#define ICONTROLADORALTACINE

#include "DtCine.h"

#include <string>
using namespace std;

class IControladorAltaCine{
    public:
        virtual void altaCine(const DtCine& dtCine, const std::vector<int>& capacidadesSalas)=0;
};

#endif