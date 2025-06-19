#include "ManejadorFinanciera.h"

ManejadorFinanciera* ManejadorFinanciera::instancia = NULL;

ManejadorFinanciera::ManejadorFinanciera() {
    financieras["Visa"] = 0.10;
    financieras["MasterCard"] = 0.15;
    financieras["Santander"] = 0.20;
    financieras["Amex"] = 0.05;
}

float ManejadorFinanciera::obtenerDescuento(const std::string& nombre) {
    std::map<std::string, float>::iterator it = financieras.find(nombre);
    if (it != financieras.end()) {
        return it->second;
    }
    return 0.0;
}

// Método estático para obtener la única instancia
ManejadorFinanciera* ManejadorFinanciera::getInstancia() {
    if (instancia == NULL) {
        instancia = new ManejadorFinanciera();
    }
    return instancia;
}
