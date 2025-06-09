#include "Pago.h"


#include <iostream>
#include <string>
using namespace std;

Pago::Pago() {montoBase = 0.0f;}
            
Pago::Pago(float montoBase){
    this->montoBase = montoBase;
}

Pago::~Pago() {}