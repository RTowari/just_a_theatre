CC = g++
SRC = DtUsuario.cpp DtSesion.cpp DtFecha.cpp DtHorario.cpp DtReserva.cpp DtPelicula.cpp DtDireccion.cpp DtCine.cpp DtDebito.cpp DtCredito.cpp DtComentario.cpp DtSala.cpp DtFuncion.cpp DtPago.cpp DtPuntaje.cpp DtInfoPelicula.cpp\
Usuario.cpp Pelicula.cpp Funcion.cpp Reserva.cpp Sesion.cpp Cine.cpp Sala.cpp Fabrica.cpp Pago.cpp Debito.cpp Credito.cpp Comentario.cpp RelojLocal.cpp Puntaje.cpp\
ControladorAltaUsuario.cpp ControladorSesion.cpp ControladorAltaPelicula.cpp ControladorCrearReserva.cpp ControladorComentarPelicula.cpp ControladorVerReserva.cpp ControladorVerComentariosyPuntajesdePelicula.cpp \
ControladorAltaCine.cpp ControladorEliminarPelicula.cpp ControladorAltaFuncion.cpp ControladorPuntuarPelicula.cpp ControladorVerInformacionPelicula.cpp ControladorRelojLocal.cpp ControladorCargarDatos.cpp\
ManejadorUsuario.cpp ManejadorPelicula.cpp ManejadorCine.cpp ManejadorFuncion.cpp ManejadorFinanciera.cpp ManejadorSala.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

main: $(OBJ)
	$(CC) $(OBJ) -o main

%.o: %.cpp
	$(CC) -c $<

clean:
	rm -rf *.o main

clean-w:
	del /F /Q *.o main.exe

clean-trash-w:
	del /F /Q *.o

clean-trash:
	rm -rf *.o *.o