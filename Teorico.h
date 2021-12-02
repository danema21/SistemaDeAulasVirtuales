#ifndef TEORICO_H
#define TEORICO_H
#include "Clase.h"
#include "DtInfoTeorico.h"

class Asignatura;


class Teorico : public Clase{
    private:
        int cantAsistentes; //atributo calculado
    public:
        Teorico();
        Teorico(int, int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*);
        void setCantAsistentes(int);
        int getCantAsistentes();

        DtInfoTeorico* getDtInfoClase();

        ~Teorico();
};

#endif