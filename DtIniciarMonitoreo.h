#ifndef DTINICIARMONITOREO
#define DTINICIARMONITOREO
#include "DtIniciarClaseFull.h"
#include <list>

using namespace std;


class DtIniciarMonitoreo : public DtIniciarClaseFull{
    private:
        list<string> habilitados;
    public:
        DtIniciarMonitoreo();
        DtIniciarMonitoreo(string, string, DtTimeStamp*, int);
        list<string> getHabilitados();
        ~DtIniciarMonitoreo();
};

#endif