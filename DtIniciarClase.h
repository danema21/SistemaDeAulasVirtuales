#ifndef DTINICIARCLASE
#define DTINICIARCLASE
#include <string>
#include "DtTimeStamp.h"

using namespace std;


class DtIniciarClase{
    private:
        string codigo;
        string nombre;
        DtTimeStamp* fechaHora;
    public:
        DtIniciarClase();
        DtIniciarClase(string, string, DtTimeStamp*);
        string getCodigo();
        string getNombre();
        DtTimeStamp* getFechaHora();
        virtual ~DtIniciarClase();
};

#endif