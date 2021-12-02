#include "DtIniciarClase.h"

DtIniciarClase::DtIniciarClase(){}

DtIniciarClase::DtIniciarClase(string codigo, string nombre, DtTimeStamp* fechaHora){
    this->codigo = codigo;
    this->nombre = nombre;
    this->fechaHora = fechaHora;
}

string DtIniciarClase::getCodigo(){
    return this->codigo;
}

string DtIniciarClase::getNombre(){
    return this->nombre;
}

DtTimeStamp* DtIniciarClase::getFechaHora(){
    return this->fechaHora;
}

DtIniciarClase::~DtIniciarClase(){}