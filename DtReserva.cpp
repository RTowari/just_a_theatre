#include "DtReserva.h"

// Default constructor
DtReserva::DtReserva() : idReserva(0), pago(nullptr) {}

// Parameterized constructor
DtReserva::DtReserva(int idReserva, DtPago* pago) {
    this->idReserva = idReserva;
    this->pago = pago;
}

// Copy constructor (deep copy of pago)
DtReserva::DtReserva(const DtReserva& other) {
    this->idReserva = other.idReserva;
    this->pago = other.pago ? other.pago->getDt() : nullptr;
}

// Destructor (delete owned pago)
DtReserva::~DtReserva() {
    delete pago;
}

// Assignment operator
DtReserva& DtReserva::operator=(const DtReserva& other) {
    if (this != &other) {
        this->idReserva = other.idReserva;
        delete this->pago;
        this->pago = other.pago ? other.pago->getDt() : nullptr;
    }
    return *this;
}

int DtReserva::getIdReserva() {
    return this->idReserva;
}

DtPago* DtReserva::getPago() {
    return this->pago;
}
