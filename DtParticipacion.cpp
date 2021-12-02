#include "DtParticipacion.h"

DtParticipacion::DtParticipacion(){}
DtParticipacion::DtParticipacion(int id, DtTimeStamp* fecha, string mensaje, DtParticipacion* responde){
    this->id = id;
    this->fecha = fecha;
    this->mensaje = mensaje;
    this->responde = responde;   
}
int DtParticipacion::getId(){
    return this->id;
}
DtTimeStamp* DtParticipacion::getFecha(){
    return this->fecha;
}

string DtParticipacion::getMensaje(){
    return this->mensaje;
}

DtParticipacion* DtParticipacion::getResponde(){
    return this->responde;
}

ostream& operator<<(ostream& salida,const DtParticipacion& dtp){
    DtTimeStamp* dts = dtp.fecha;
    salida<<"Mensaje "<< dtp.id << endl;
    salida<<"==================="<<endl;
    salida<< *dts <<endl;
    salida<< dtp.mensaje <<endl;
    if(dtp.responde != NULL){
        salida<<"Responde al mensaje "<< dtp.responde->getId() <<endl;
        salida<<"De texto: --> "<< dtp.responde->getMensaje() <<endl;
    }
    return salida;
}

DtParticipacion::~DtParticipacion(){}