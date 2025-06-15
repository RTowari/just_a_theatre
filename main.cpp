#include <iostream>
#include <limits>

#include "Fabrica.h"

#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtComentario.h"

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
IControladorEliminarPelicula* iconEliminarPelicula;
IControladorComentarPelicula* iconComentarPelicula;
IControladorAltaFuncion* iconAltaFuncion;

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

//CASO 11
void comentarPelicula();

// OPERACIONES AUXILIARES
void pausarPantalla();

// OPERACIONES DE DESBUGUEO
void verPeliculas();

//CASO 1 (IMPLEMENTACION)
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

void altaFuncion(){

	bool continuar = true;

	while(continuar) {
		cout <<"_____________________________________________" <<endl;
		cout <<"_____________ALTA__FUNCION____________"<< endl;

		// primero listo todas las peliculas registradas
		// obtengo los titulos

		std::list<std::string> titulos = iconCrearReserva->listarPeliculas();

		// Imprimir los títulos con numeros
		cout << "*PELICULAS*" << endl;
		int index = 1;
		std::list<std::string>::iterator it;
		for (it = titulos.begin(); it != titulos.end(); ++it) {
			cout << index << ". " << *it << endl;
			index++;
		}

		// Pedir al usuario que seleccione un número
		int seleccion;
		cout << "Elige la pelicula usando numeros: " << endl;
		cin >> seleccion;

		// Obtener la película seleccionada en formado clase
		it = titulos.begin();
		advance(it, seleccion - 1);

		// Le seteo a mi icon el titulo de la pelicula seleccionada (no la clase, solo la string del titulo)
		iconAltaFuncion->setTi(*it);

		// Listo los cines
		list<DtCine> cines = iconAltaFuncion->listarCines();
		
		// Imprimo los cines. el usuario mas tarde eligira el cine usando la ID del mismo
		cout << "*CINES*" << endl;
		index = 1;
		std::list<DtCine>::iterator itCines;
		for (itCines = cines.begin(); itCines != cines.end(); ++itCines) {
			cout << "ID:  " << itCines->getId();
			cout << " | Direccion: " << itCines->getDireccion().getCalle() << " " << itCines->getDireccion().getNumero() << endl;  // Asumiendo que DtCine tiene getNombre()
			index++;
		}
		cout << "Elige el cine usando numeros: " << endl;
		cin >> seleccion;

		// setea el id del cine que eligio el usuario como una int en el controlador
		iconAltaFuncion->setIdC(seleccion);

		// le doy a mi usuario todas las salas del cine que eligio antes para que elija una de ellas
		list<DtSala> salas = iconAltaFuncion->listarSalasDeCine();

		// itero en un for loop imprimiendo las salas
		cout << "*SALAS*" << endl;
		index = 1;
		list<DtSala>::iterator itSalas;
		for(itSalas = salas.begin(); itSalas != salas.end(); ++itSalas) {
			cout << "ID: " << itSalas->getId() << endl;
			cout << "Capacidad restante: " << itSalas->getCapacidad() << endl;
			index++;
		}
		cout << "Elige la sala usando numeros: " << endl;
		cin >> seleccion;

		// ahora que mi usuario escogio una sala, seteo la variable de la sala dentro del controlador para usarla mas tarde
		iconAltaFuncion->setIdS(seleccion);

		// fragmento de codigo que le pide a mi usuario fecha y hora y usa eso para armar esos dos DT.
		// tras eso ambos Dt se ponen adentro de las variables de la clase controlador
		int anio;
		int mes;
		int dia;
		cout << "Elige el anio para la funcion: ";
		cin >> anio;
		cout << endl << "Elige el mes para la funcion: ";
		cin >> mes;
		cout << endl << "Elige el dia para la funcion: ";
		cin >> dia;
		cout << endl << "DATOS INGRESADOS: | ANIO: " << anio << " | MES: " << mes << " | DIA: " << dia << endl;
		DtFecha dtFecha(dia, mes, anio);

		string horaComienzo;
		string horaFin;
		cout << "Elige a que hora comienza la funcion: ";
		cin >> horaComienzo;
		cout << "Elige a que hora termina la funcion: ";
		cin >> horaFin;
		cout << endl << "DATOS INGRESADOS: | HORA DE COMIENZO: " << horaComienzo  << " | HORA DE FINALIZACION: " << horaFin << endl;
		DtHorario dtHorario(horaComienzo, horaFin);

		iconAltaFuncion->setDtFecha(dtFecha);
		iconAltaFuncion->setDtHorario(dtHorario);

		// ahora se llama a la funcion final para poner Funciona adentro de la sala adentro del cine
		iconAltaFuncion->agregarFuncionASala();

		//Pregunti si el usuario quiere continuar
		int respuesta;
		cout << "Desea agregar otra funcion? (Si: 1 | No: 0)" << endl;
		cin >> respuesta;
		if(respuesta == 0){
			continuar = false;
		}
	}
}

//CASO 4 (IMPLEMENTACION)
void altaPelicula(){
    //system("clear");
	cin.ignore();
	cout <<"_____________________________________________" <<endl;
	cout <<"______ALTA__PELICULA_______"<< endl;
	string titulo, sinopsis, poster;
	float puntaje;
	cout << "TITULO: ";
	getline(cin,titulo);
	cout << endl << "SINOPSIS: ";
	getline(cin,sinopsis);
	cout << endl << "POSTER: ";
	getline(cin,poster);

	puntaje = 0;
	iconAltaPelicula->altaPelicula(titulo, sinopsis, puntaje, poster);
}

void eliminarPelicula(){

	cout <<"_____________________________________________" <<endl;
	cout <<"______ELIMINAR__PELICULA_______"<< endl;
	
	string titulo;
	
	try{
		iconEliminarPelicula->listarPeliculas();

		cout << "Pelicula a eliminar: " << endl;
		getline(cin,titulo);

		if(titulo != "c"){
			cout << titulo << endl;
			iconEliminarPelicula->eliminarPelicula(titulo);
		}else{
			cout << "Operacion cancelada" << endl;
		}
	}catch(const runtime_error& e){
		cout << e.what() << endl;	
	}

	pausarPantalla();
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

//CASO 11 (IMPLEMENTACION)
void comentarPelicula() {

	cin.ignore();

    cout << "_____________________________________________" << endl;
    cout << "_____________COMENTAR__PELICULA____________" << endl;

    string titulo, comentario, linea;
    int indiceComentario = -1;

    cout << "Peliculas disponibles." << endl;
    // Muestro las películas
    vector<DtPelicula> peliculas = iconComentarPelicula->listarPeliculas();
    for (int i = 0; i < peliculas.size(); i++) {
        cout << "-" << peliculas[i].getTitulo() << endl;
    }

    cout << "\n" << "Titulo de pelicula a comentar: " << endl;
    getline(cin, titulo);  // Lee línea completa sin problemas

    vector<DtComentario> comentarios = iconComentarPelicula->listarComentarios(titulo);

    int eleccion;
    cout << "1) Nuevo Comentario" << endl;
    cout << "2) Responder comentario" << endl;

    getline(cin, linea);
	eleccion = stoi(linea);

    if (eleccion == 2) {
        if (comentarios.size() > 0) {
            for (int i = 0; i < comentarios.size(); i++) {
                cout << i << ") " << comentarios[i].getTexto() << endl;
            }
            cout << "Seleccione comentario a responder: " << endl;
            getline(cin, linea);
			indiceComentario = stoi(linea);
		}
        else {
            cout << "No hay comentarios." << endl;
        }
    }

    cout << "Comentario: " << endl;
    getline(cin, comentario);  // Ya buffer limpio, no hay problema

    iconComentarPelicula->comentarPelicula(titulo, comentario, indiceComentario);

    pausarPantalla();
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
		cout <<"1. Alta Pelicula"<<endl;
		cout <<"2. Ver Peliculas"<<endl;
		cout <<"3. Eliminar pelicula"<<endl;
		cout <<"4. Alta Cine" << endl;
		cout <<"5. Crear Reserva" << endl;
		cout <<"6. Comentar Pelicula" << endl;
		cout <<"7. Alta Funcion" << endl;
		cout <<"0. Cerrar Sesion" << endl;
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
	iconEliminarPelicula = fabrica->getIControladorEliminarPelicula();
	iconComentarPelicula = fabrica->getIControladorComentarPelicula();
	iconAltaFuncion = fabrica->getIControladorAltaFuncion();
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
							case 0: cerrarSesion();
								break;
							case 1: altaPelicula();
								break;
							case 2: verPeliculas();
								break;
							case 3: eliminarPelicula();
								break;
							case 4: altaCine();
								break;
							case 5: crearReserva();
								break;
							case 6: comentarPelicula();
								break;
							case 7: altaFuncion();
								break;
							default: cout << "Opcion no valida. Intente nuevamente." << endl;
								break;
						}
					}while(opc != 0);
					
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
void verPeliculas(){

	try{
		iconEliminarPelicula->listarPeliculas();
	}catch(const runtime_error& e){
		cout << e.what() << endl;
	}

	pausarPantalla();
}

					
