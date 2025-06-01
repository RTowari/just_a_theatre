#include "ControladorAltaUsuario.h"
#include "ManejadorUsuario.h"
#include "Usuario.h"

void ControladorAltaUsuario::altaUsuario(string nickname, string contrasenia, string urlFoto){
    
    // creo un usuario con los datos que me paso
    Usuario* user = new Usuario(nickname, contrasenia, urlFoto);

    // Llamo a la instancia de manejador y luego le paso el usuario para que lo agregue
    ManejadorUsuario::getInstancia()->agregarUsuario(user);


}