#ifndef ICINSCRIPCIONASIGNATURA
#define ICINSCRIPCIONASIGNATURA

#include <string>
#include <list>

using namespace std;

class ICInscripcionAsignatura{
    public:
        virtual list<string> asignaturasNoInscripto(string)=0;
        virtual void selectAsignatura(string)=0;
        virtual void inscribir(string)=0;
        virtual bool perfilesVacio()=0;
        virtual bool asignaturasVacio()=0;
        virtual bool clasesVacio()=0;
};

#endif