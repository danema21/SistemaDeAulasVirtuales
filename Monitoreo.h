#ifndef MONITOREO_H
#define MONITOREO_H
#include "Clase.h"
#include "Estudiante.h"
#include "ManejadorPerfil.h"
#include "DtInfoMonitoreo.h"

class Asignatura;


class Monitoreo : public Clase{
    private:
        map<string, Estudiante*> estudiantes;
    public:
        Monitoreo();
        Monitoreo(int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*, list<string>);
        ~Monitoreo();

        DtInfoMonitoreo* getDtInfoClase();
};

#endif