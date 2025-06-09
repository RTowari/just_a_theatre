#include <iostream>

#include "IControladorAltaPelicula.h"
#include "IControladorAltaUsuario.h"
#include "IControladorSesion.h"
#include <limits>
#include "IControladorCrearReserva.h"
#include "IControladorAltaCine.h"
#include "Fabrica.h"

#include "DtPelicula.h"
#include "DtCine.h"
//PARA DESBUGUEO
#include "Pelicula.h"
#include "ManejadorPelicula.h"

using namespace std;

Fabrica * fabrica;
IControladorAltaUsuario* iconAltaUsuario;
IControladorSesion* iconSesion;
IControladorAltaPelicula* iconAltaPelicula;
IControladorAltaCine* iconAltaCine;
IControladorCrearReserva* iconCrearReserva;

//CASO 1
bool iniciarSesion();

//CASO 2
void cerrarSesion();

//CASO 3
void altaUsuario();

//CASO 4
void altaPelicula();

// CASO 5
void altaCine();

//CASO 7
void crearReserva();


// OPERACIONES AUXILIARES
void pausarPantalla();

// OPERACIONES DE DESBUGUEO
void verPeliculas();

//CASO 1 (IMPLEMENTACION)
bool iniciarSesion() {
    //system("clear");
    cout << "_____________________________________________" << endl;
    cout << "______INICIAR SESION_______" << endl;

    string nickname, contrasenia;
	bool sesionIniciada = false;
    

    while (!sesionIniciada) {
	
		cout << "NICKNAME: ";
	    cin >> nickname;

        // Solicitar contraseña
        cout << "\nCONTRASENIA: ";
        cin >> contrasenia;

        // Intento de inicio de sesión
        sesionIniciada = iconSesion->iniciarSesion(nickname, contrasenia);

        if (sesionIniciada) {
            sesionIniciada = true; // Inicio exitoso, salimos del loop saque el break
        }

        // Mensaje de error y opciones
        cout << "_____________________________________________" << endl;
        cout << "Credenciales incorrectas" << endl;
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

//CASO 2 (IMPLEMENTACION)
void cerrarSesion(){

    iconSesion->cerrarSesion();

    //cout << "Sesion cerrada correctamente." << endl;

	//pausarPantalla();
}

//CASO 3 (IMPLEMENTACION)
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

//CASO 5 (IMPLEMENTACION)
void altaCine(){	
    system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______ALTA__CINE_______"<< endl;
	DtCine dtcine;
	DtDireccion dtdireccion;
	string calle;
	int numero;
	int cantSalas;
	vector<int> capacidadesSalas;

	cout << "Ingrese la calle de cine: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, calle);
	cout << endl << "Ingrese el numero puerta: ";
    cin >> numero;
	 //creamos instancia dtdireccion
	dtdireccion = DtDireccion(calle, numero);
	dtcine = DtCine(dtdireccion);


	cout << endl << "Ingrese la cantidad (1-20) de salas que tendra el Cine: ";
	cin >> cantSalas;
	if (cantSalas <= 0 || cantSalas > 20)
	throw invalid_argument("\nERROR: Ingrese cantidad de salas entre 1 y 20");
	
	for (int i = 0; i < cantSalas; ++i) {
        int capacidadActual;
        cout << "Ingrese la capacidad para la Sala " << (i + 1) << ": ";
        cin >> capacidadActual;

        if (capacidadActual <= 0) {
            throw std::invalid_argument("ERROR: La capacidad de la sala debe ser un numero positivo.");
        }
        capacidadesSalas.push_back(capacidadActual);
    }
 	int confirmacion;
    cout << endl << "Confirmar el alta del cine con estos datos (1-Si / 0-No): ";
    cin >> confirmacion;
    // Manejo de error para la entrada de confirmación
	if (confirmacion < 0 || confirmacion > 1)
		throw invalid_argument("\nERROR: Ingrese 1-Sí / 0-No");
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer después de leer int

    if (confirmacion == 1) {// Confirmar si ingresó 1
		try {
        	iconAltaCine->altaCine(dtcine, capacidadesSalas);			
   	    } 
		catch (const std::invalid_argument& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    	}		
	}
	else ("INFO: Alta de cine cancelada por el usuario");
}

//CASO 4 (IMPLEMENTACION)
void altaPelicula(){
    //system("clear");
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

//CASO 7 (IMPLEMENTACION)
void crearReserva(){
	cout <<"_____________________________________________" <<endl;
	cout <<"_____________CREAR__RESERVA____________"<< endl;
	
	// primero listo todas las peliculas registradas
	// obtengo los titulos

	std::list<std::string> titulos = iconCrearReserva->listarPeliculas();

	// Imprimir los títulos con numeros
	cout << "0. [Cancelar operacion]" << endl;
	int index = 1;
	std::list<std::string>::iterator it;
    for (it = titulos.begin(); it != titulos.end(); ++it) {
        cout << index << ". " << *it << endl;
        index++;
    }

	// Pedir al usuario que seleccione un número
    int seleccion;
    cout << "Ingrese el número de la película que desea reservar: ";
    cin >> seleccion;

	// Obtener la película seleccionada
    it = titulos.begin();
    advance(it, seleccion - 1);

	DtPelicula pelElegida = iconCrearReserva->elegirDtPelicula(*it);

	// imprimo poster y sipnosis
	cout << "POSTER: " << pelElegida.getPoster() << endl;
	cout << "SIPNOSIS: " << pelElegida.getSinopsis() << endl;
	cout << "_____________________________________________" <<endl;
	cout << "1. Seleccionar un cine" << endl;
	cout << "2. Cancelar" << endl;
	cout <<"_____________________________________________" <<endl;
	cout <<"OPCION: ";
	cin >> seleccion;

	// segun la seleccion salgo de la funcion o listo los cines
	switch(seleccion) {
		case 1:
			// Lógica para cine
			

			
			



			break;
		case 2:
			cout << "Operación cancelada." << endl;
			return; // Salir de la función
	}


}

// MENU
void menuLogin(){
    	//system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________CINE____________"<< endl;
		cout <<"1. Iniciar Sesion"<<endl;
		cout <<"2. Registrar Usuario"<<endl;
		cout <<"3. Salir"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

void menu(){
		//system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________CINE____________"<< endl;
		cout <<"1. Registrar Pelicula"<<endl;
		cout <<"2. Ver Peliculas"<<endl;
		cout <<"3. Cerrar Sesion"<<endl;
		cout <<"4. Alta Pelicula (IMPLEMENTADA SOLO CON DESBUGUEO)" << endl;
		cout <<"5. Alta Cine" << endl;
		cout <<"7. Crear Reserva"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

int main(){
    fabrica = Fabrica::getInstancia();
    iconAltaUsuario = fabrica->getIControladorAltaUsuario();
    iconSesion = fabrica->getIControladorSesion();
    iconAltaPelicula = fabrica->getIControladorAltaPelicula();
	iconAltaCine = fabrica->getIControladorAltaCine();
	iconCrearReserva = fabrica->getIControladorCrearReserva();
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
							case 4: altaPelicula();
								break;
							case 5: altaCine();
								break;
							case 7: crearReserva();
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

//OPERACIONES DE DESBUGUEO
void verPeliculas(){	//FUNCION DE PRUEBA PARA COMPROBAR ALTAPELICULA  
	ManejadorPelicula* manejador;

	manejador = manejador->getInstancia();
	manejador->verPeliculas();
	pausarPantalla();
}
