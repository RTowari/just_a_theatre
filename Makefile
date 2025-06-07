# Aca fede. Vamos a usar este formato para los make file porque sino nos vamos a volver locos con tanto archivo
#Ta chetooo
CC = g++
SRC = DtUsuario.cpp Usuario.cpp ControladorAltaUsuario.cpp ControladorSesion.cpp ManejadorUsuario.cpp \
      Fabrica.cpp Sesion.cpp DtSesion.cpp Pelicula.cpp Funcion.cpp DtFecha.cpp DtHorario.cpp \
      ManejadorPelicula.cpp ControladorAltaPelicula.cpp Cine.cpp Sala.cpp ManejadorCine.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

main: $(OBJ)
	$(CC) $(OBJ) -o main

%.o: %.cpp
	$(CC) -c $<

clean:
	rm -rf *.o main

clean-w:
	del /F /Q *.o main.exe