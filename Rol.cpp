#include "Rol.h"

Rol::Rol(){}

Rol::Rol(TipoRol tipo, Asignatura* asignatura){
    this->tipo = tipo;
    this->asignatura=asignatura;
}

TipoRol Rol::getTipo(){
    return this->tipo;
}

void Rol::setRol(TipoRol tipo){
    this->tipo = tipo;
}

Asignatura* Rol::getAsignatura(){
    return this->asignatura;
}

bool Rol::esAsignatura(string cod){
    return (cod == asignatura->getCodigo());
}

void Rol::setAsignatura(Asignatura* asignatura){
    this->asignatura = asignatura;
}

string Rol::getCodigoAsignatura(){
    return this->asignatura->getCodigo();
}

void Rol::eliminarAsignatura(){
    this->asignatura = NULL;
}

Rol::~Rol(){}