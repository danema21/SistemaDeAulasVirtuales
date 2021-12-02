#ifndef ASISTEENVIVO
#define ASISTEENVIVO

#include"Estudiante.h"
#include "DtTimeStamp.h"

class Estudiante;

class AsisteEnVivo{
    private:
        DtTimeStamp* inicio;
        DtTimeStamp* fin;
        Estudiante* estudiante;
    public:
        AsisteEnVivo();
        AsisteEnVivo(DtTimeStamp*, DtTimeStamp*, Estudiante*);

        void setInicio(DtTimeStamp*);
        DtTimeStamp* getInicio();

        void setFin(DtTimeStamp*);
        DtTimeStamp* getFin();

        void setEstudiante(Estudiante*);
        Estudiante* getEstudiante();

        ~AsisteEnVivo();

};
#endif