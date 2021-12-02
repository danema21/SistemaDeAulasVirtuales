#include"DtTimeStamp.h"


DtTimeStamp::DtTimeStamp(){}

DtTimeStamp::DtTimeStamp(DtFecha* fecha, int hora, int minuto, int segundo){
    this->fecha = fecha;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

DtFecha* DtTimeStamp::getFecha(){
    return this->fecha;
}
int DtTimeStamp::getHora(){
    return this->hora;
}
int DtTimeStamp::getMinuto(){
    return this->minuto;
}
int DtTimeStamp::getSegundo(){
    return this->segundo;
}

DtTimeStamp::~DtTimeStamp(){}

ostream& operator << (ostream& salida, const DtTimeStamp& timestamp){
    salida << *(timestamp.fecha) << endl;
    salida << "Hora: " << timestamp.hora;
    salida << ":" << timestamp.minuto;
    salida << ":" << timestamp.segundo;

    return salida;
}
