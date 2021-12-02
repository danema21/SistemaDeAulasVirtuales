#include "DtInfoTeorico.h"


DtInfoTeorico::DtInfoTeorico(){}

DtInfoTeorico::DtInfoTeorico(int id, string nombre, Docente* docente, int cantAsistentes):DtInfoClase(id, nombre, docente){
    this->cantAsistentes=cantAsistentes;
}

int DtInfoTeorico::getCantAsistentes(){
    return this->cantAsistentes;
}

ostream& operator << (ostream& salida, const DtInfoTeorico& dtit){
    salida << "Cantidad de Asistentes: " << dtit.cantAsistentes << endl;
    return salida;
}

DtInfoTeorico::~DtInfoTeorico(){}