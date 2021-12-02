#ifndef DTTIMESTAMP
#define DTTIMESTAMP
#include "DtFecha.h"
#include <iostream>

using namespace std;

class DtTimeStamp: public DtFecha{
    private:
        DtFecha* fecha;
        int hora;
        int minuto;
        int segundo;
    public:
        DtTimeStamp();
        DtTimeStamp(DtFecha*, int, int, int);
        DtFecha* getFecha();
        int getHora();
        int getMinuto();
        int getSegundo();

        ~DtTimeStamp();
        friend ostream& operator <<(ostream& ,const DtTimeStamp&);
}; 

#endif