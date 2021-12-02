#include "DtIniciarClaseFull.h"

DtIniciarClaseFull::DtIniciarClaseFull(){}

DtIniciarClaseFull::DtIniciarClaseFull(string codigo, string nombre, DtTimeStamp* fechaHora, int id):DtIniciarClase(codigo, nombre, fechaHora){
    this->id = id;
}

int DtIniciarClaseFull::getId(){
    return this->id;
}

DtIniciarClaseFull::~DtIniciarClaseFull(){}