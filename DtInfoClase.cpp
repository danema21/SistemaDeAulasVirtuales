#include "DtInfoClase.h"

DtInfoClase::DtInfoClase(){}

DtInfoClase::DtInfoClase(int id, string nombre, Docente* docente){
    this->id = id;
    this->nombre = nombre;
    this->docente = docente;
}

int DtInfoClase::getId(){
    return this->id;
}

string DtInfoClase::getNombre(){
    return this->nombre;
}

Docente* DtInfoClase::getDocente(){
    return this->docente;
}

ostream& operator << (ostream& salida, const DtInfoClase& dtic){
    salida << "Id de la clase: " << dtic.id << endl;
    salida << "Nombre de la clase: " << dtic.nombre << endl;
    salida << "Docente a cargo: " << dtic.docente->getNombre() << endl;

    return salida;
}

DtInfoClase::~DtInfoClase(){}