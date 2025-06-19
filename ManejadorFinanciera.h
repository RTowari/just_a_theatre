#ifndef MANEJADORFINANCIERA_H
#define MANEJADORFINANCIERA_H

#include <string>
#include <map>

class ManejadorFinanciera {
private:
    static ManejadorFinanciera* instancia;
    std::map<std::string, float> financieras;

    ManejadorFinanciera();
public:
    static ManejadorFinanciera* getInstancia();
    
    float obtenerDescuento(const std::string& nombre);
};

#endif