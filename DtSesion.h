#ifndef DTSESION
#define DTSESION

#include <string>
using namespace std;

class DtSesion{
private:
    string nickname;
    string contrasenia;

public:
    DtSesion();
    DtSesion(string nickname, string contrasenia);
    string getNickname();
    string getContrasenia();
    ~DtSesion();
};

#endif