#include "DtIniciarMonitoreo.h"

DtIniciarMonitoreo::DtIniciarMonitoreo(){}

DtIniciarMonitoreo::DtIniciarMonitoreo(string codigo, string nombre, DtTimeStamp* fechaHora, int id):DtIniciarClaseFull(codigo, nombre, fechaHora, id){}

list<string> DtIniciarMonitoreo::getHabilitados(){
    return this->habilitados;
}

DtIniciarMonitoreo::~DtIniciarMonitoreo(){}