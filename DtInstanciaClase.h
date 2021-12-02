#ifndef INSTANCIACLSE
#define INSTANCIACLSE

#include <iostream>

using namespace std;

class DtInstanciaClase{
    private:
        bool teorico;
        bool practico;
        bool monitoreo;
    public:
        DtInstanciaClase();
        DtInstanciaClase(bool, bool, bool);
        bool getTeorico();
        bool getPractico();
        bool getMonitoreo();
        ~DtInstanciaClase();

        friend ostream& operator << (ostream&, const DtInstanciaClase&);

};

#endif