main: DtUsuario.o Usuario.o main.o ControladorSesion.o ManejadorUsuario.o Fabrica.o
	g++ DtUsuario.o Usuario.o ControladorSesion.o ManejadorUsuario.o Fabrica.o main.o -o main

DtUsuario.o: DtUsuario.cpp

Usuario.o: Usuario.cpp

ControladorSesion.o: ControladorSesion.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp

Fabrica.o: Fabrica.cpp

main.o: main.cpp

clean:
	rm -rf *.o main