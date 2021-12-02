#ifndef DTPARTICIPACION
#define DTPARTICIPACION
#include <string>
#include "DtTimeStamp.h"

using namespace std;

class DtParticipacion{
    private:
        int id;
        DtTimeStamp* fecha;
        string mensaje;
        DtParticipacion* responde;
    public:
        DtParticipacion();
        DtParticipacion(int, DtTimeStamp*, string, DtParticipacion*);
        int getId();
        DtParticipacion* getResponde();
        DtTimeStamp* getFecha();
        string getMensaje();
        ~DtParticipacion();
        friend ostream& operator<<(ostream&,const DtParticipacion&);
};
#endif