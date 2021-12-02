#ifndef CLISTADOCLASES
#define CLISTADOCLASES
#include "DtInfoClase.h"
#include "ManejadorAsignatura.h"
#include "ManejadorPerfil.h"
#include "Asignatura.h"
#include "ICListadoClases.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

class CListadoClases: public ICListadoClases{
    public:
        CListadoClases();
        list<string> asignaturasAsignadas(string);
        map<int, DtInfoClase*> selectAsignatura(string);
        ~CListadoClases();
};

#endif