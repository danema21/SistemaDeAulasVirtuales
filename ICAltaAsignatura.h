#ifndef ICALTAASIGNATURA
#define ICALTAASIGNATURA
#include "DtAsignatura.h"

class ICAltaAsignatura{
    public:
        virtual DtAsignatura* ingresar(DtAsignatura*)=0;
        virtual void altaAsignatura()=0;
        virtual void cancelar()=0;
        virtual bool existeAsignatura(string) = 0;

};

#endif