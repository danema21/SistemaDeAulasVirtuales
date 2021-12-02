#include "CAltaAsignatura.h"
#include "ManejadorAsignatura.h"
#include "Asignatura.h"

CAltaAsignatura::CAltaAsignatura(){}

DtAsignatura* CAltaAsignatura :: ingresar(DtAsignatura* datosAsignatura){
    this->datosAsignatura = datosAsignatura;
    return this->datosAsignatura;
}

void CAltaAsignatura :: altaAsignatura(){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* asignatura = new Asignatura(datosAsignatura->getCodigo(),
                                            datosAsignatura->getNombre(),
                                            datosAsignatura->getTipoClases());
                                            
    mA->add(asignatura);
}

void CAltaAsignatura :: cancelar(){
    delete datosAsignatura;
}

CAltaAsignatura::~CAltaAsignatura(){}

bool CAltaAsignatura::existeAsignatura(string codigo){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    return mA->existeAsignatura(codigo);
}