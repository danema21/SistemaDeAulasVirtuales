#ifndef DTASIGNATURA
#define DTASIGNATURA
#include "DtInstanciaClase.h"
#include <string>
#include <iostream>

using namespace std;

class DtAsignatura{
    private:
        string nombre;
        string codigo;
        DtInstanciaClase* tipoClases;
    public:
        DtAsignatura();
        DtAsignatura(string, string, DtInstanciaClase*);
        string getNombre();
        string getCodigo();
        DtInstanciaClase* getTipoClases();
        ~DtAsignatura();

        friend ostream& operator << (ostream&, const DtAsignatura&);

};
#endif