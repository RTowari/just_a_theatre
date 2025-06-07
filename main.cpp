#include <iostream>

#include "IControladorAltaPelicula.h"
#include "IControladorAltaUsuario.h"
#include "IControladorSesion.h"
#include "Fabrica.h"

#include "ManejadorPelicula.h" //SE INCLUYE PARA COMPROBAR ALTAPELICULA

Fabrica * fabrica;
IControladorAltaUsuario* iconAltaUsuario;
IControladorSesion* iconSesion;
IControladorAltaPelicula* iconAltaPelicula;

//OPERACION A
bool iniciarSesion();

//OPERACION B
void cerrarSesion();

//OPERACION C
void altaUsuario();

//OPERACION D
void altaPelicula();
void verPeliculas();
//Operacion auxiliar para pausar la pantalla
void pausarPantalla();


bool iniciarSesion() {
    system("clear");
    cout << "_____________________________________________" << endl;
    cout << "______INICIAR SESION_______" << endl;

    string nickname, contrasenia;
	bool sesionIniciada = false;
    
    cout << "NICKNAME: ";
    cin >> nickname;

    while (!sesionIniciada) {
        // Solicitar contraseña
        cout << "\nCONTRASENIA: ";
        cin >> contrasenia;

        // Intento de inicio de sesión
        sesionIniciada = iconSesion->iniciarSesion(nickname, contrasenia);

        if (sesionIniciada) {
            break; // Inicio exitoso, salimos del loop
        }

        // Mensaje de error y opciones
        cout << "_____________________________________________" << endl;
        cout << "Contrasenia incorrecta" << endl;
        cout << "1. Intentar nuevamente" << endl;
        cout << "2. Volver al menu principal" << endl;
        cout << "_____________________________________________" << endl;
        cout << "OPCION: ";

        int opcion;
        cin >> opcion;

        if (opcion == 2) {
            return false; // Salir y volver al menú
        }

        cout << "_____________________________________________" << endl;
    }

    return true; // Sesión iniciada correctamente
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
	bool altaExitosa = false;

	while(altaExitosa == false) {

		cout << "NICKNAME: ";
		cin >> nickname;
		cout << endl << "FOTO: ";
		cin >> urlFoto;
		cout << endl << "CONTRASENIA: ";
		cin >> contrasenia;
		cout << endl;

		// me fijo si hay un usuario con este nickname en el manejador
		bool existenciaUsuario = iconAltaUsuario->existeUsuario(nickname);

		//Si el usuario no existe, entonces registro
		if(existenciaUsuario == false){
			iconAltaUsuario->altaUsuario(nickname, contrasenia, urlFoto);
			
			altaExitosa = true;
		} else {
			cout << "Error: el usuario " << nickname << " ya existe. Vuelve a intentarlo" << endl;
			cout <<"_____________________________________________" <<endl;
		}
	}
}

//OPERACION D (IMPLEMENTACION)
void altaPelicula(){
    system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______ALTA__PELICULA_______"<< endl;
	string titulo, sinopsis, poster;
	float puntaje;
	cout << "TITULO: ";
	cin >> titulo;
	cout << endl << "SINOPSIS: ";
	cin >> sinopsis;
	cout << endl << "POSTER: ";
	cin >> poster;

	puntaje = 0;
	iconAltaPelicula->altaPelicula(titulo, sinopsis, puntaje, poster);
}

void verPeliculas(){	//FUNCION DE PRUEBA PARA COMPROBAR ALTAPELICULA  
	ManejadorPelicula* manejador;

	manejador = manejador->getInstancia();
	manejador->verPeliculas();
	pausarPantalla();
}


void menuLogin(){
    	system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________CINE____________"<< endl;
		cout <<"1. Iniciar Sesion"<<endl;
		cout <<"2. Registrar Usuario"<<endl;
		cout <<"3. Salir"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

void menu(){
		system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________CINE____________"<< endl;
		cout <<"1. Registrar Pelicula"<<endl;
		cout <<"2. ver pelis"<<endl;
		cout <<"3. Cerrar Sesion"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

int main(){
    fabrica = Fabrica::getInstancia();
    iconAltaUsuario = fabrica->getIControladorAltaUsuario();
    iconSesion = fabrica->getIControladorSesion();
    iconAltaPelicula = fabrica->getIControladorAltaPelicula();
	int opcion, opc;
    do{
		menuLogin();
		cin >> opcion;
		
		switch(opcion){
			case 1: 
				if(iniciarSesion()){
					do{
						menu();
						cin >> opc;
						switch(opc){
							case 1: altaPelicula();
								break;
							case 2: verPeliculas();
								break;
							case 3: cerrarSesion();
								break;
							default: cout << "Opcion no valida. Intente nuevamente." << endl;
								break;
						}
					}while(opc != 3);
					
				}
				break;
			case 2: altaUsuario();
				break;
			case 3: cout << "\nSaliendo del programa..." <<endl;
				break;
			default: cout << "Opcion no valida. Intente nuevamente." << endl;
				break;
        }

	}while(opcion != 3);
	
}


//OPERACIONES AUXILIARES
void pausarPantalla(){
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

