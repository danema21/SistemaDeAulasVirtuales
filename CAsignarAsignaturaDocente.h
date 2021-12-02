#ifndef CASIGNARASIGNATURADOCENTE
#define CASIGNARASIGNATURADOCENTE
#include "ManejadorAsignatura.h"
#include "ManejadorPerfil.h"
#include "ICAsignarAsignaturaDocente.h"
#include <string>
#include "Rol.h"

using namespace std;

struct CAsignarAsignaturaDocente: public ICAsignarAsignaturaDocente{
    private:
        string cod;
        TipoRol rol;
        string email;
    public:
    CAsignarAsignaturaDocente();
    list<string> listarAsignaturas();
    list<string> docentesSinLaAsignatura(string);
    void selectDocente(string,TipoRol);
    void asignarDocente();

    ~CAsignarAsignaturaDocente();

};

#endif