#ifndef CONTROLADORALTACINE
#define CONTROLADORALTACINE
#include <vector> 
#include <string>
#include "DtCine.h"
#include "IControladorAltaCine.h"

using namespace std;

class ControladorAltaCine:public IControladorAltaCine{
    public:
        void altaCine(const DtCine& dtCine, const std::vector<int>& capacidadesSalas);
};

#endif