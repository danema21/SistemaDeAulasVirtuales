#ifndef ASIGNATURA
#define ASIGNATURA
#include <string>
#include <map>
#include <list>
#include "Clase.h"
#include "DtInstanciaClase.h"
#include "ManejadorClase.h"
#include "DtInfoClase.h"

//#include "Teorico.h"
//#include "Practico.h"
//#include "Monitoreo.h"

//#include "DtInfoTeorico.h"
//#include "DtInfoMonitoreo.h"

using namespace std;

class Clase;
class DtInfoClase;

class Asignatura{
    private:
        string codigo;
        string nombre;
        DtInstanciaClase* tipoClases;
        map<int, Clase*> clases;
    public:
        Asignatura();
        Asignatura(string, string, DtInstanciaClase*);
        void setCodigo(string);
        void setNombre(string);
        string getCodigo();
        string getNombre();
        DtInstanciaClase* getTipoClases();
        void agregarClase(Clase*);
        list<int> getClases();
        bool noTieneClases();
        map<int,DtInfoClase*> getDtInfoClase();
        
        ~Asignatura();
};


#endif