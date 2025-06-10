<<<<<<< HEAD
CC = g++
SRC = DtUsuario.cpp DtSesion.cpp DtFecha.cpp DtHorario.cpp DtReserva.cpp DtPelicula.cpp DtDireccion.cpp DtCine.cpp DtDebito.cpp DtCredito.cpp \
Usuario.cpp Pelicula.cpp Funcion.cpp Reserva.cpp Sesion.cpp Cine.cpp Sala.cpp Fabrica.cpp Pago.cpp Debito.cpp Credito.cpp  \
ControladorAltaUsuario.cpp ControladorSesion.cpp ControladorAltaPelicula.cpp ControladorCrearReserva.cpp ControladorAltaCine.cpp \
ManejadorUsuario.cpp ManejadorPelicula.cpp ManejadorCine.cpp ManejadorFuncion.cpp main.cpp
=======
# Aca fede. Vamos a usar este formato para los make file porque sino nos vamos a volver locos con tanto archivo

CC = g++
SRC = DtUsuario.cpp Usuario.cpp ControladorAltaUsuario.cpp ControladorSesion.cpp ManejadorUsuario.cpp \
      Fabrica.cpp Sesion.cpp DtSesion.cpp Pelicula.cpp Funcion.cpp DtFecha.cpp DtHorario.cpp \
      ManejadorPelicula.cpp ControladorAltaPelicula.cpp main.cpp
>>>>>>> parent of 78acd6f (semi implementados los alta en el back)

OBJ = $(SRC:.cpp=.o)

main: $(OBJ)
	$(CC) $(OBJ) -o main

%.o: %.cpp
	$(CC) -c $<

clean:
	rm -rf *.o main

clean-w:
	del /F /Q *.o main.exe