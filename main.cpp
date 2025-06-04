#include <iostream>

#include "IControladorAltaPelicula.h"
#include "IControladorAltaUsuario.h"
#include "IControladorSesion.h"
#include "Fabrica.h"

Fabrica * fabrica;
IControladorAltaUsuario* iconAltaUsuario;
IControladorSesion* iconSesion;

//OPERACION A
bool iniciarSesion();

//OPERACION B
void cerrarSesion();

//OPERACION C
void altaUsuario();

//OPERACION D
void altaPelicula();

//Operacion auxiliar para pausar la pantalla
void pausarPantalla();


//OPERACION A (IMPLEMENTACION)
bool iniciarSesion(){
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

	return loginExitoso;

}

//OPERACION B (IMPLEMENTACION)
void cerrarSesion(){

    iconSesion->cerrarSesion();

    //cout << "Sesion cerrada correctamente." << endl;

	//pausarPantalla();
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


void menuLogin(){
    	system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________CINE____________"<< endl;
		cout <<"1. Iniciar Sesion"<<endl;
		cout <<"2. Registrar Usuario"<<endl;
		cout <<"3. Cerrar Sesion"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

void menu(){


}

int main(){
    fabrica = Fabrica::getInstancia();
    iconAltaUsuario = fabrica->getIControladorAltaUsuario();
    iconSesion = fabrica->getIControladorSesion();
    int opcion;
    menuLogin();
    cin >> opcion;
    while(opcion != 4){
		switch(opcion){
			case 1: if(iniciarSesion()){
				while(opcion != 2){
					switch(opcion){
						case 1: cout<<"altaPelicula"<<endl;
						case 2: cout<<"Salir"<<endl;
					}
				}
			}
			break;
			case 2: altaUsuario();
				break;
			case 3: cerrarSesion();
				break;
			default: cout << "Opcion no valida. Intente nuevamente." << endl;
				break;
        }
		menuLogin();
		cin >> opcion;
	}
}


//OPERACIONES AUXILIARES
void pausarPantalla(){
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

