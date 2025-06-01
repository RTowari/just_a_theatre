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
    while(opcion != 3){
		switch(opcion){
			case 1: iniciarSesion();
				break;
			case 2: altaUsuario();
				break;
        }
		menu();
		cin >> opcion;
	}
}