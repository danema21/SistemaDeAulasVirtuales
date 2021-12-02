#ifndef ICALTAUSUARIO
#define ICALTAUSUARIO
#include "DtPerfil.h"

class ICAltaUsuario{
    public:
        virtual void ingresarDatosPerfil(DtPerfil*)=0;
        virtual void ingresarDocente(string)=0;
        virtual void ingresarEstudiante(string)=0;
        virtual void altaUsuario()=0;
        virtual bool existeUsuario(string)=0;

        virtual void cancelar()=0;
};

#endif