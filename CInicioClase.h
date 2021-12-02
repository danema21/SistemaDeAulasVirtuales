#ifndef CINICIOCLASE
#define CINICIOCLASE
#include <string>
#include "DtIniciarClaseFull.h"
#include "ICInicioClase.h"
#include "Teorico.h"
#include "Practico.h"
#include "Monitoreo.h"
#include "ManejadorClase.h"
#include "ManejadorPerfil.h"
#include "ManejadorAsignatura.h"


using namespace std;

class CInicioClase : public ICInicioClase{
    private:
        DtIniciarClase* inicioClase;
        DtIniciarClaseFull* data;
        list<string> habilitados;
    public:
        CInicioClase();
        list<string> asignaturasAsignadas(string);
        bool selectAsignatura(DtIniciarClase*, string);
        list<string> inscriptosAsignaturas();
        void habilitar(string);
        DtIniciarClaseFull* datosIngresados();
        void iniciarClase(string);
        void cancelar();

        bool perfilesVacio();
        bool asignaturasVacio();
        bool clasesVacio();

        ~CInicioClase();
};

#endif