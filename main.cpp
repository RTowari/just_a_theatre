#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

#include "Fabrica.h"

#include "DtPelicula.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "DtComentario.h"
#include "DtPuntaje.h"
#include "DtReserva.h"
#include "DtPago.h"
#include "DtCredito.h"
#include "DtDebito.h"

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
IControladorPuntuarPelicula* iconPuntuarPelicula;
IControladorAltaFuncion* iconAltaFuncion;
IControladorVerReserva* iconVerReserva;


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

// CASO 6
void altaFuncion();

//CASO 7
void crearReserva();
string elegirPelicula();
bool mostrarInformacionPelicula();
map<int, pair<int, int>> mapearFunciones(list<DtSala> salasConFunciones);
// CASO 10
void puntuarPelicula();

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
		cout << endl << "DATOS INGRESADOS | ANIO: " << anio << " | MES: " << mes << " | DIA: " << dia << endl;
		DtFecha dtFecha(dia, mes, anio);

		int mComienzo;
		int hComienzo;
		int mFin;
		int hFin;

		cout << endl << "Elige a que hora comienza la funcion: ";
		cin >> hComienzo;
		cout << endl << "Elige en que minuto comienza la funcion: ";
		cin >> mComienzo;

		cout << endl << "Elige a que hora termina la funcion: ";
		cin >> hFin;
		cout << endl << "Elige en que minuto termina la funcion: ";
		cin >> mFin;

		cout << endl << "DATOS INGRESADOS | HORA DE COMIENZO: " << hComienzo << ":" << mComienzo
		<< " | HORA DE FINALIZACION: " << hFin << ":" << mFin << endl;
		
		DtHorario dtHorario(mComienzo, hComienzo, mFin, hFin);

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
	string titulo, sinopsis, poster;
	float puntaje;
	int eleccion;
	
	do{
		cin.ignore();
		cout <<"_____________________________________________" <<endl;
		cout <<"______ALTA__PELICULA_______"<< endl;
		cout << "TITULO: " << endl;
		getline(cin,titulo);

		eleccion = 0;

		if(iconAltaPelicula->existePelicula(titulo) == true){
			cout << "La pelicula ya existe en el sistema" << endl;
			cout << "1) Ingresar otra pelicula." << endl;
			cout << "2) Salir" << endl;
			cin >> eleccion;
		}
	}while(eleccion == 1); //se repite mientras el usuario quiera agregar una pelicula

	if(eleccion != 2){		//si el usuario decide no salir
		cout << endl << "SINOPSIS: " << endl;
		getline(cin,sinopsis);
		cout << endl << "POSTER: " << endl;
		getline(cin,poster);

		puntaje = 0.0;
		iconAltaPelicula->altaPelicula(titulo, sinopsis, puntaje, poster);
		
		cout << "Pelicula agregada." << endl;
	}
}

void eliminarPelicula(){

	cin.ignore();

	cout <<"_____________________________________________" <<endl;
	cout <<"______ELIMINAR__PELICULA_______"<< endl;
	
	string titulo;
	
	vector<DtPelicula> peliculas = iconEliminarPelicula->listarPeliculas();

	if(peliculas.size() > 0){
		for (int i = 0; i < peliculas.size(); i++) {
			cout << "-" << peliculas[i].getTitulo() << endl;
		}
		cout << "Pelicula a eliminar: " << endl;
		getline(cin,titulo);

		if(titulo != "c"){
			iconEliminarPelicula->eliminarPelicula(titulo);
		}else{
			cout << "Operacion cancelada" << endl;
		}
	
	}else{
		cout << "No hay peliculas en el sistema" << endl;
	}

	pausarPantalla();
}

// para cu crearReserva
// lista los titulos de las peliculas y devuelve el que eligio el usuario
string elegirPelicula(){
	std::list<std::string> titulos = iconCrearReserva->listarPeliculas();

	cout << "0. [Cancelar operacion]" << endl;
	int index = 1;
	std::list<std::string>::iterator tituloIt;
	for (tituloIt = titulos.begin(); tituloIt != titulos.end(); ++tituloIt) {
		cout << index << ". " << *tituloIt << endl;
		index++;
	}

	// Pedir al usuario que seleccione un número
	int seleccion;
	cout << "Ingrese el numero de la pelicula que desea: " << endl;
	cin >> seleccion;

	if (seleccion == 0) {
		cout << "Operacion cancelada." << endl;
		return "";
	}

	// Obtener la película seleccionada usando el numero del usuario
	std::list<std::string>::iterator selectedTituloIt = titulos.begin();
	std::advance(selectedTituloIt, seleccion - 1);

	return *selectedTituloIt;
}
// muesta la informacion particular de la pelicula y devuelve un int que ser refiere a la seleccion del usuario
bool mostrarInformacionPelicula(DtPelicula& peli){
	int seleccion = 0;
	cout << endl << "POSTER: " << peli.getPoster() << endl;
	cout << "SIPNOSIS: " << peli.getSinopsis() << endl;
	cout << "_____________________________________________" <<endl;
	cout << "1. Seleccionar un cine" << endl;
	cout << "2. Cancelar" << endl;
	cout <<"_____________________________________________" <<endl;
	cout <<"OPCION: ";

	int opcion;
	cin >> opcion;
	return opcion == 1;
}
// lista los cines y devuelve el cine que el usuario eligio
int elegirCine(list <DtCine> cines){
	
	if(cines.empty()){
		return 0;
	}
	// Imprimo los cines. el usuario mas tarde eligira el cine usando la ID del mismo
	int seleccion = 0;
	cout << endl << "*CINES*" << endl;

	std::list<DtCine>::iterator cineIt;
	for (cineIt = cines.begin(); cineIt != cines.end(); ++cineIt) {
		cout << "ID: " << cineIt->getId();
		cout << " | Direccion: " << cineIt->getDireccion().getCalle() << " " << cineIt->getDireccion().getNumero() << endl;
	}
		
	cout << "Elige el cine usando numeros: ";
	cin >> seleccion;

	return seleccion;
}
map<int, pair<int, int>> mapearFunciones(list<DtSala> salasConFunciones){
	cout << endl << "*SALAS*" << endl;
	// este es un map que voy a usar para mapear las funciones adentro de la sala
	map<int, pair<int, int>> funcionSelector;
	int funcionIndex = 1;

	list<DtSala>::iterator salaIt;
	// este for itera en las salas para acceder a cada funcion
	for (salaIt = salasConFunciones.begin(); salaIt != salasConFunciones.end(); ++salaIt) {
		int salaId = salaIt->getId();

		// en este mapa, guardo las funciones que me retorna mi sala (la sala en la que estoy en el for)
		map<int, DtFuncion> dtFunciones = salaIt->getDtFunciones();
		// este es el iterador que se movera por la lista de funciones de la sala
		map<int, DtFuncion>::iterator funcionIt;

			// a partir de ahora empiezo a iterar en mi lista de funciones locales
		for (funcionIt = dtFunciones.begin(); funcionIt != dtFunciones.end(); ++funcionIt) {
			int funcionId = funcionIt->first;

			//de la lista esta es la funcion local con la que estoy trabajando
			DtFuncion funcion = funcionIt->second;

			cout << funcionIndex << ". SALA " << salaId
			<< " | FUNCION " << funcionId
			<< " | Hora: " << funcion.getHorario().getHoraComienzo()
			<< ":" << setw(2) << setfill('0') << funcion.getHorario().getMinutoComienzo() << endl;

			// funcionSelector es un map
			// lo que hago es asignar una key al par de Id de sala y funcion
			// cuando el usuario me de el numero, me va a dar un numero asociado a esta combinacion
			// esto me permite elegir una funcion sin necesidad de escribir la Id para sala
			funcionSelector[funcionIndex] = make_pair(salaId, funcionId);
			funcionIndex++;
		}
	}

	return funcionSelector;
}

void crearReserva(){
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"_____________CREAR__RESERVA____________"<< endl;


	bool eligiendoFuncion = true;

	while(eligiendoFuncion){
		
		// lista las peliculas, el usuario elige una, y devuelve la string que eligio
		// despues seteo el titulo en el controlador para usarlo en el back
		std::string titulo = elegirPelicula();
		if (titulo.empty()) return;
		iconCrearReserva->setTitulo(titulo);
		
		// imprimo poster y sipnosis en esta funcion y le pregunto al usuario si quiere continuar
		DtPelicula pelElegida = iconCrearReserva->elegirDtPelicula();
		if(!mostrarInformacionPelicula(pelElegida)) return;


		// usando el titulo listo los cines como Dt
		int cineElegido = elegirCine(iconCrearReserva->listarCines());
		iconCrearReserva->setIdC(cineElegido);
		
		



		list<DtSala> salasConFunciones = iconCrearReserva->listarFuncionesDeCine();
		map<int, pair<int, int>> funcionSelector = mapearFunciones(salasConFunciones);

		cout << "Opciones:" << endl;
		cout << "1. Elegir otra pelicula" << endl;
		cout << "2. Elegir una funcion" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;

		if (opcion == 1) {
			// vuelve a elegir pelicula (continúa el while)
			continue;
		} else if (opcion == 2) {
			cout << endl << "Elija el numero de la funcion que desea reservar: ";
			int eleccionFuncion;
			cin >> eleccionFuncion;

			pair<int, int> seleccionFuncion = funcionSelector[eleccionFuncion]; // obtiene la dupla idSala idFuncion que eligio el usuario
			int salaElegida = seleccionFuncion.first;
			int funcionElegida = seleccionFuncion.second;

			cout << endl << "Seleccionaste la funcion " << funcionElegida << " en la sala " << salaElegida << "." << endl;

			int eleccionAsientos;
			cout << endl << "Cuantos asientos desea reservas?" << endl;
			cin >> eleccionAsientos;
			iconCrearReserva->setTotalDeAsientos(eleccionAsientos);

			int modoPago;
			cout << endl << "Selecciona un modo de pago usando numeros (Debito: 0 | Credito: 1) " << endl;
			cin >> modoPago;

			// si paga con debito
			if(modoPago == 0){
				string bancoNombre;
				cout << endl << "Ingrese el banco para pagar con debito: " << endl;
				cin >> bancoNombre;
				cout << endl << "El precio total es: " << iconCrearReserva->setPagoDebito(bancoNombre) << endl;
			}
			// si paga con credito
			else if(modoPago == 1){
				string financiera;
				cout << endl << "Ingrese el nombre de la financiera: " << endl;
				cin >> financiera;

				float descuento = iconCrearReserva->consultarDescuento(financiera);
				if(descuento > 0){
					cout << "Tu descuento es del: " << iconCrearReserva->consultarDescuento(financiera) << endl;
					iconCrearReserva->setDescuento(iconCrearReserva->consultarDescuento(financiera));
					cout << endl << "El precio total es: " << iconCrearReserva->setPagoCredito(financiera) << endl;
				}
				else{
					cout << endl << "No hay descuento para esta financiera" << endl;
					iconCrearReserva->setDescuento(0);
					cout << endl << "El precio total es: " << iconCrearReserva->setPagoCredito(financiera) << endl;
				}
			}

			cout << endl << "Desea continuar o cancelar? (Cancelar: 0 | Continuar: 1)" << endl;
			int cancelarPago;
			cin >> cancelarPago;
			if(cancelarPago == 0){
				return;
			}

			iconCrearReserva->confirmarReserva(funcionElegida, salaElegida);

			cout << endl << "La reserva se creo con exito" << endl;

			return; // Termina luego de elegir la función

		}
	}
}

void verReservas(){
	cout << "_____________________________________________" << endl;
    cout << "_____________VER__RESERVAS____________" << endl;
	// primero listo las peliculas y le digo al usuario que elija una
	
	std::string titulo = elegirPelicula();

	// ahora que el usuario eligio una consigo los dt con las funciones que tienen peliculas
	std::list<DtFuncion> dtFuncion_own_list = iconVerReserva->listarReservas(titulo);
	if (dtFuncion_own_list.empty()){
        cout << endl << "No hay funciones para esta pelicula " << endl;
    }
	cout << endl << "*FUNCIONES*" << endl;
	for(std::list<DtFuncion>::iterator it = dtFuncion_own_list.begin(); it != dtFuncion_own_list.end(); ++it) {
		DtFuncion dtFuncion_own = *it;

		std::cout << std::endl << "Funcion ID: " << dtFuncion_own.getId() << std::endl;
		std::list<DtReserva> dtReserva_own_list = dtFuncion_own.getReservas();

		if(dtFuncion_own.getReservas().empty()){
			cout << endl << "  No hay reservas para esta funcion" << endl;
		}
		else{
			for(std::list<DtReserva>::iterator it = dtReserva_own_list.begin(); it != dtReserva_own_list.end(); ++it){
				DtPago* dtPago_ptr = it->getPago();

				if (DtCredito* credito_ptr = dynamic_cast<DtCredito*>(dtPago_ptr)) {
					std::cout << endl << "  Pago con credito" << endl;
					std::cout << endl << "  Se compraron " << credito_ptr->getCantidadEntradas() << " entradas" << endl;
					std::cout << endl << "  El costo total fue de " <<credito_ptr->getTotal() << endl;
				
				} else if (DtDebito* debito_tr = dynamic_cast<DtDebito*>(dtPago_ptr)) {
					std::cout << endl << "  Pago con debito" << std::endl;
					std::cout << endl << "  Se compraron " << debito_tr->getCantidadEntradas() << " entradas" << endl;
					std::cout << endl << "  El costo total fue de " << debito_tr->getTotal() << endl;
				
				} else {
					throw std::runtime_error("[ERROR CATASTROFICO] El tipo de pago no se reconoce");
				}
			}
		}
	}
}

//CASO 10 (IMPLEMENTACION)

void puntuarPelicula() {

	cin.ignore();

    cout << "_____________________________________________" << endl;
    cout << "_____________PUNTUAR__PELICULA____________" << endl;

    string titulo;
    int nuevoPuntaje;

    cout << "Peliculas disponibles." << endl;
    // Muestro las películas
    vector<DtPelicula> peliculas = iconPuntuarPelicula->listarPeliculas();
 	if (peliculas.empty()) {
            cout << "No hay peliculas disponibles para puntuar en el sistema." << endl;
            // No hay nada más que hacer si no hay películas
            cout << "_____________________________________________" << endl;
            return;
    }

    for (int i = 0; i < peliculas.size(); i++) {
        cout << "-" << peliculas[i].getTitulo() << endl;
    }

    cout << "\n" << "Titulo de pelicula a puntuar: " << endl;
    getline(cin, titulo);  // Lee línea completa sin problemas
	try {
		int puntajeAnterior = iconPuntuarPelicula->obtienePuntajeUsuario(titulo);
		if (puntajeAnterior > 0){//Usuario ya puntuo pelicula
			cout << "\n¡Ya has puntuado esta película!" << endl;
			cout << "Tu puntaje actual para '" << titulo << "' es: " << puntajeAnterior << endl;

			int opcionModificar;
			std::cout << "¿Deseas modificar tu puntaje? (1-Sí / 0-No): ";
			cin >> opcionModificar;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (opcionModificar == 1) {
				// Modificar el puntaje: solicitar el nuevo valor
				cout << "Ingresa tu nuevo puntaje para '" << titulo << "' (entre 1 y 100): ";
				cin >> nuevoPuntaje;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				try {
					iconPuntuarPelicula->puntuarPelicula(titulo, nuevoPuntaje);
				} 
				catch (const std::exception& e) {
					cerr << "ERROR al registrar/modificar puntaje: " << e.what() << endl;
				}
			} 
			else {
				cout << "INFO: No se modificara el puntaje. Hasta Luego" << endl;
			}
		}
		else {//usuario nunca puntuo la pelicula
			cout << "\nNunca has puntuado la pelicula '" << titulo << "'." << endl;
			cout << "Ingresa tu puntaje (entre 1 y 100): ";
			cin >> nuevoPuntaje;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			try {
				iconPuntuarPelicula->puntuarPelicula(titulo, nuevoPuntaje);
				cout << "Puntaje registrado con exito" << endl;
			} 
			catch (const exception& e) {
				cerr << "ERROR al registrar puntaje: " << e.what() << std::endl;
			}
		}
	}catch(const exception& e) {
		cerr << "ERROR al buscar pelicula elegida: " << e.what() << endl;
	}
    pausarPantalla();
}

//CASO 11 (IMPLEMENTACION)
void comentarPelicula() {

	cin.ignore();

    cout << "_____________________________________________" << endl;
    cout << "_____________COMENTAR__PELICULA____________" << endl;

    string titulo, comentario, linea;
    int indiceComentario = -1;
	bool repetir = false;
    vector<DtPelicula> peliculas = iconComentarPelicula->listarPeliculas();
	
	if(peliculas.size() > 0){
		cout << "Peliculas disponibles." << endl;
		// Muestro las películas
		for (int i = 0; i < peliculas.size(); i++) {
			cout << "-" << peliculas[i].getTitulo() << endl;
		}

		cout << "\n" << "Titulo de pelicula a comentar: " << endl;
		getline(cin, titulo);  // Lee línea completa sin problemas

		vector<DtComentario> comentarios = iconComentarPelicula->listarComentarios(titulo);

	do{
		int eleccion;
		cout << "__________________________" << endl;
		cout << "1) Nuevo Comentario" << endl;
		cout << "2) Responder comentario" << endl;
		cout << "--------------------------------" << endl;

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
				repetir = true;
			}
		}

	}while(repetir == true);
	
	cout << "Comentario: " << endl;
	getline(cin, comentario);  // Ya buffer limpio, no hay problema

	iconComentarPelicula->comentarPelicula(titulo, comentario, indiceComentario);

	}else{
		cout << "No hay peliculas en el sistema." << endl;
	}

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
		cout <<"8. Ver Reservas" << endl;
		cout <<"9. Puntuar Pelicula" << endl;
		cout <<"0. Cerrar Sesion" << endl;
		cout <<"_____________________________________________" <<endl;
		cout << "OPCION: " << endl;
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
	iconPuntuarPelicula = fabrica->getIControladorPuntuarPelicula();
	iconAltaFuncion = fabrica->getIControladorAltaFuncion();
	iconVerReserva = fabrica->getIControladorVerReserva();
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
							case 8: verReservas();
								break;
							case 9: puntuarPelicula();
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
   // cin.ignore();
    cin.get();
}

//OPERACIONES DE DESBUGUEO
void verPeliculas(){

	ManejadorPelicula::getInstancia()->verPeliculas();

	pausarPantalla();
}

					
