#include "DtUsuario.h"
#include "Usuario.h"

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
    cout << "Hola A" << endl;
}

//OPERACION B (IMPLEMENTACION)
void altaUsuario(){
    cout << "Hola B" << endl;
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