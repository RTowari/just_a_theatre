main: DtUsuario.o Usuario.o main.o
	g++ DtUsuario.o Usuario.o main.o -o main

DtUsuario.o: DtUsuario.cpp

Usuario.o: Usuario.cpp

main.o: main.cpp

clean:
	rm -rf *.o