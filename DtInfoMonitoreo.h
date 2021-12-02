#ifndef DTINFOMONITOREO
#define DTINFOMONITOREO
#include "DtInfoClase.h"
#include <string>
#include <list>

class Docente;

using namespace std;

class DtInfoMonitoreo: public DtInfoClase{
    private:
        list<string> estudiantes;
    public:
        DtInfoMonitoreo();
        DtInfoMonitoreo(int, string, Docente*);
        void agregarEstudiante(string);
        ~DtInfoMonitoreo();

        friend ostream& operator << (ostream&, DtInfoMonitoreo&);

};

#endif