#ifndef DTINICIARCLASEFULL
#define DTINICIARCLASEFULL
#include "DtIniciarClase.h"

class DtIniciarClaseFull : public DtIniciarClase{
    private:
        int id;
    public:
        DtIniciarClaseFull();
        DtIniciarClaseFull(string, string, DtTimeStamp*, int);
        int getId();
        virtual ~DtIniciarClaseFull();
};

#endif