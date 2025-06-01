#include "DtUsuario.h"
#include "Usuario.h"
#include "Sesion.h"

#include <iostream>


#include "IControladorAltaUsuario.h"
#include "IControladorSesion.h"
#include "Fabrica.h"

Fabrica * fabrica;
IControladorAltaUsuario* iconAltaUsuario;
IControladorSesion* iconSesion;

//OPERACION A
void iniciarSesion();

//OPERACION B
void cerrarSesion();

//OPERACION C
void altaUsuario();

//Operacion auxiliar para pausar la pantalla
void pausarPantalla();


//OPERACION A (IMPLEMENTACION)
void iniciarSesion(){
    system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______INICIAR__SESION_______"<< endl;
	string nickname, contrasenia;
	cout << "NICKNAME: ";
	cin >> nickname;
	
	bool loginExitoso = false;
	while(!loginExitoso) {
		cout << endl << "CONTRASENIA: ";
		cin >> contrasenia;

		loginExitoso = iconSesion->iniciarSesion(nickname, contrasenia);
        
		if (!loginExitoso) {
            cout << "Contraseña incorrecta. Intenta nuevamente." << endl;
        }

	}
}

//OPERACION B (IMPLEMENTACION)
void cerrarSesion(){
    system("clear");
    cout << "_____________________________________________" << endl;
    cout << "______CERRAR SESION_______" << endl;

    Usuario* usuarioActual = Sesion::getInstancia()->getUsuario();

    if (usuarioActual != NULL) {
        cout << "Usuario que cierra sesion: " << usuarioActual->getNickname() << endl;
    } else {
        cout << "No hay sesion activa." << endl;
    }

    iconSesion->cerrarSesion();

    cout << "Sesion cerrada correctamente." << endl;

	pausarPantalla();
}

//Operacion auxiliar para pausar la pantalla
void pausarPantalla(){
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

//OPERACION C (IMPLEMENTACION)
void altaUsuario(){
    system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______ALTA__USUARIO_______"<< endl;
	string nickname, contrasenia, urlFoto;
	cout << "NICKNAME: ";
	cin >> nickname;
	cout << endl << "FOTO: ";
	cin >> urlFoto;
	cout << endl << "CONTRASENIA: ";
	cin >> contrasenia;

	iconAltaUsuario->altaUsuario(nickname, contrasenia, urlFoto);

}


void menu(){
    	system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________CINE____________"<< endl;
		cout <<"1. Iniciar Sesion"<<endl;
		cout <<"2. Registrar Usuario"<<endl;
		cout <<"3. Cerrar Sesion"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}


int main(){
    fabrica = Fabrica::getInstancia();
    iconAltaUsuario = fabrica->getIControladorAltaUsuario();
    iconSesion = fabrica->getIControladorSesion();
    int opcion;
    menu();
    cin >> opcion;
    while(opcion != 4){
		switch(opcion){
			case 1: iniciarSesion();
				break;
			case 2: altaUsuario();
				break;
			case 3: cerrarSesion();
				break;
			default: cout << "Opcion no valida. Intente nuevamente." << endl;
				break;
        }
		menu();
		cin >> opcion;
	}
}


