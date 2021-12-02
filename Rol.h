#ifndef ROL
#define ROL
#include "TipoRol.h"
#include "Asignatura.h"

class Asignatura;

class Rol{
    private: 
        TipoRol tipo;
        Asignatura* asignatura;
    public:
        Rol();
        Rol(TipoRol,Asignatura*);
        TipoRol getRol();
        void setRol(TipoRol);
        TipoRol getTipo();
        Asignatura* getAsignatura();
        void setAsignatura(Asignatura* asignatura);
        string getCodigoAsignatura();
        bool esAsignatura(string);
        void eliminarAsignatura();//exel en te 
        ~Rol();
};

#endif