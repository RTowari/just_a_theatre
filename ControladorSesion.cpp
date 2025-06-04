#include "ManejadorUsuario.h"
#include "ControladorSesion.h"
#include "Sesion.h"

#include <stdexcept>

bool ControladorSesion::usuarioExiste(string nickname){
    ManejadorUsuario* mU = ManejadorUsuario::getInstancia();

    bool existenciaUsuario = mU->existeUsuario(nickname);

    return existenciaUsuario;
}

bool ControladorSesion::iniciarSesion(string nickname, string contrasenia) {
    
    try{
        // Obtengo la instancia del manejador
        ManejadorUsuario* mU = ManejadorUsuario::getInstancia();

        // Busco el usuario dado el nickname
        Usuario* U = mU->buscarUsuario(nickname);

        // Obtengo la contrasenia del usuario iniciando sesion
        string p = U->getContrasenia();
        
        // Si mi usuario puso la contraseña incorrecta, hago throw para que vaya al catch, que devuelve false
        if(p != contrasenia) { // Si las contraseñan coinciden, setea el usuario
            throw runtime_error("Contraseña incorrecta.");
        }

         // Esto se asegura de que tengo una instancia de Sesion
         // Despues pone al usuario en la susodicha sesion
        Sesion::getInstancia()->setUsuario(U);

        return true;

    } catch (const runtime_error& e) {
        return false;
    }
}

void ControladorSesion::cerrarSesion(){
    Sesion::getInstancia()->cerrarSesion();
}




