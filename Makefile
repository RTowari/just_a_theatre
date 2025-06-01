main: DtUsuario.o Usuario.o main.o ControladorAltaUsuario.o ControladorSesion.o ManejadorUsuario.o Fabrica.o Sesion.o DtSesion.o
	g++ DtUsuario.o Usuario.o ControladorAltaUsuario.o ControladorSesion.o ManejadorUsuario.o Fabrica.o DtSesion.o Sesion.o main.o -o main

DtUsuario.o: DtUsuario.cpp

Usuario.o: Usuario.cpp

ControladorAltaUsuario.o: ControladorAltaUsuario.cpp

ControladorSesion.o: ControladorSesion.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp

Fabrica.o: Fabrica.cpp

Sesion.o: Sesion.cpp

DtSesion: DtSesion.cpp

main.o: main.cpp

clean:
	rm -rf *.o main

clean-w:
	del /F /Q *.o main.exe