#ifndef ICELIMINARASIGNATURA
#define ICELIMINARASIGNATURA
#include <iostream>
#include <list>

using namespace std;

class ICEliminarAsignatura{
    public:
        virtual list<string> listarAsignaturas()=0;
        virtual void selectAsignatura(string)=0;
        virtual void eliminarAsignatura()=0;
        virtual void cancelar()=0;
        virtual bool existeAsignatura(string)=0;
};

#endif