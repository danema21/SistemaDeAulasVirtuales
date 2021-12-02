#ifndef MANEJADORASIGNATURA
#define MANEJADORASIGNATURA
#include "Asignatura.h"
#include <map>
#include <list>

class ManejadorAsignatura{
    private:
        static ManejadorAsignatura* instancia;
        ManejadorAsignatura();
        map <string, Asignatura*> asignaturas;
    public:
        void add(Asignatura*);
        Asignatura* find(string);
        bool existeAsignatura(string);
        list<string> listarAsignatura();
        static ManejadorAsignatura* getInstancia();
        bool estaVacio();
        void destroy(string);
        map<string, Asignatura*> getAsignaturas();

        
  
        ~ManejadorAsignatura();
};

#endif