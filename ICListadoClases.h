#ifndef ICLISTADOCLASES
#define ICLISTADOCLASES
#include <list>
#include "DtInfoClase.h"
#include <iostream>

using namespace std;

class ICListadoClases{
    public:
        virtual list<string> asignaturasAsignadas(string)=0;
        virtual map<int, DtInfoClase*> selectAsignatura(string)=0;
};

#endif