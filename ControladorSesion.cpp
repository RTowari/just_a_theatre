#include "ManejadorUsuario.h"
#include "ControladorSesion.h"
#include "Sesion.h"

#include <stdexcept>

bool ControladorSesion::iniciarSesion(string nickname, string contrasenia) {
    
        // Obtengo la instancia del manejador
        ManejadorUsuario* mU = ManejadorUsuario::getInstancia();

        // Busco el usuario dado el nickname
        Usuario* U = mU->buscarUsuario(nickname);

        if(U == nullptr){
            cout << "La variable U en ControladorSesion devolvio NULL" << endl;
            return false;
        }

        try{
            // Obtengo la contrasenia del usuario iniciando sesion
            string p = U->getContrasenia();

            // Si mi usuario puso la contraseña incorrecta, hago throw para que vaya al catch, que devuelve false
            if(p != contrasenia) { // Si las contraseñan coinciden, setea el usuario
                throw runtime_error("Contraseña incorrecta.");
            }
            
        // Catch para contraseña incorrecta
        } catch (const runtime_error& e) {
            return false;
        }
        

         // Esto se asegura de que tengo una instancia de Sesion
         // Despues pone al usuario en la susodicha sesion
        Sesion::getInstancia()->setUsuario(U);

        return true;

}

void ControladorSesion::cerrarSesion(){
    Sesion::getInstancia()->cerrarSesion();
}


