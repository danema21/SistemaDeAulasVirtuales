#ifndef CELIMINARASIGNATURA
#define CELIMINARASIGNATURA
#include "ICEliminarAsignatura.h"
#include "ManejadorAsignatura.h"
#include "ManejadorPerfil.h"
#include <iostream>

using namespace std;

class CEliminarAsignatura : public ICEliminarAsignatura{
    private:
        string cod;
    public:
        CEliminarAsignatura();        
        list<string> listarAsignaturas();
        void selectAsignatura(string);
        void eliminarAsignatura();
        void cancelar();
        bool existeAsignatura(string);

        ~CEliminarAsignatura();

};

#endif