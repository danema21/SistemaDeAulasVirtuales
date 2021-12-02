#include "DtInstanciaClase.h"

DtInstanciaClase:: DtInstanciaClase(){}

DtInstanciaClase:: DtInstanciaClase(bool teorico, bool practico, bool monitoreo){
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
}
bool DtInstanciaClase:: getTeorico(){
    return this->teorico;
}
bool DtInstanciaClase:: getPractico(){
    return this->practico;
}

bool DtInstanciaClase:: getMonitoreo(){
    return this->monitoreo;
}

DtInstanciaClase::~DtInstanciaClase(){}

ostream& operator << (ostream& salida, const DtInstanciaClase& instanciaClase){
    if(instanciaClase.teorico){
        cout << "Teorico: Habilitado" << endl;
    } else{
        cout << "Teorico: No Habilitado" << endl;
    }
    
    if(instanciaClase.practico){
        cout << "Practico: Habilitado" << endl;
    } else{
        cout << "Practico: No Habilitado" << endl;
    }

    if(instanciaClase.monitoreo){
        cout << "Monitoreo: Habilitado" << endl;
    } else{
        cout << "Monitoreo: No Habilitado" << endl;
    }

    return salida;
}