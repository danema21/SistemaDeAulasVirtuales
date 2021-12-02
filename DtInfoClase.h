#ifndef DTINFOCLASE
#define DTINFOCLASE
#include "Docente.h"
#include <string>

class Docente;
class Clase;

using namespace std;

class DtInfoClase{
    private:
        int id;
        string nombre;
        Docente* docente;
    public:
        DtInfoClase();
        DtInfoClase(int, string, Docente*);
        int getId();
        string getNombre();
        Docente* getDocente();

        friend ostream& operator << (ostream&, const DtInfoClase&);

        virtual ~DtInfoClase();

};

#endif