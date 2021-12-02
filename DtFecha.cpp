#include "DtFecha.h"

DtFecha::DtFecha(){}
DtFecha::DtFecha(int dia, int mes, int anio){ 
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DtFecha::getDia(){
    return this->dia;
}
int DtFecha::getMes(){
    return this->mes;
}
int DtFecha::getAnio(){
    return this->anio;
}
DtFecha::~DtFecha(){}

ostream& operator << (ostream& salida, const DtFecha& fecha){
    salida << "Fecha: " << fecha.dia;
    salida << "/" << fecha.mes ;
    salida << "/" << fecha.anio;

    return salida;
}