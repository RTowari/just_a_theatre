#include "ControladorAltaCine.h"
#include "ManejadorCine.h"
#include "Cine.h"
#include "DtCine.h"
#include <iostream>             
#include <stdexcept>            
#include <vector>              

using namespace std;


void ControladorAltaCine::altaCine(const DtCine& dtCine, const std::vector<int>& capacidadesSalas){
    Cine* nuevoCine = nullptr;
    try {
        ManejadorCine* mC = ManejadorCine::getInstancia();
        int idCine = mC->getSiguienteIdCine();
        nuevoCine = new Cine(idCine, dtCine.getDireccion());
        //    El ManejadorCine se encarga de agregar nuevoCine a su colección y generar los IDs para las Salas.
        //    Tambien va a* crear las Salas y agregarlas a 'nuevoCine'.
        mC->darDeAltaCine(nuevoCine, capacidadesSalas);
        cout << "INFO: Cine '" << dtCine.getDireccion() << "' (ID: " << idCine << ") y sus salas dados de alta exitosamente." << endl;
    } catch (const std::invalid_argument& e) {
        cerr << "ERROR en Alta Cine (argumento inválido): " << e.what() << endl;
        if (nuevoCine != nullptr) {
            delete nuevoCine;
            nuevoCine = nullptr;
        }
     } catch (const std::exception& e) {
        // Capturamos cualquier otra excepción estándar no capturada específicamente antes.
        cerr << "ERROR inesperado durante Alta Cine: " << e.what() << endl;
        // Realizar limpieza similar si 'nuevoCine' fue creado antes de la excepción
        if (nuevoCine != nullptr) {
            delete nuevoCine;
            nuevoCine = nullptr;
        }
    }
}