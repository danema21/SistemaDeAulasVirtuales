#ifndef PRACTICO_H
#define PRACTICO_H
#include "Clase.h"

class Practico : public Clase{
    public:
        Practico();
        Practico(int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*);
        ~Practico();

        DtInfoClase* getDtInfoClase();
};

#endif