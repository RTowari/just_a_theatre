#ifndef SESION
#define SESION

#include "Usuario.h"
#include <string>

class Sesion{
private:
    static Sesion* instancia;
    Usuario* usuarioLogueado;
    Sesion();
    Sesion(const Sesion&) = delete;             // Evitar copia
    Sesion& operator=(const Sesion&) = delete;  // Evitar asignación

public:
    static Sesion* getInstancia();
    void setUsuario(Usuario* u);
    Usuario* getUsuario();
    void cerrarSesion();
    virtual ~Sesion();
};

#endif