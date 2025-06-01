#include "ManejadorUsuario.h"
#include "ControladorSesion.h"

bool ControladorSesion::iniciarSesion(string nickname, string contrasenia) {
    // Obtengo la instancia del manejador
    ManejadorUsuario* mU = ManejadorUsuario::getInstancia();

    // Busco el usuario dado el nickname
    Usuario* U = mU->buscarUsuario(nickname);

    // Obtengo la contrasenia del usuario iniciando sesion
    string p = U->getContrasenia();
}

