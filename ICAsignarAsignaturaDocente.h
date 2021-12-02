#ifndef ICASIGNARASIGNATURADOCENTE
#define ICASIGNARASIGNATURADOCENTE
#include <list>
#include <map>
#include <string>
#include "TipoRol.h"
using namespace std;

class ICAsignarAsignaturaDocente{
    public:
        virtual list<string> listarAsignaturas()=0;//desconfio
        virtual list<string> docentesSinLaAsignatura(string)=0;
        virtual void selectDocente(string,TipoRol)=0;
        virtual void asignarDocente()=0;
};

#endif