#include "DtAsistir.h"

DtAsistir::DtAsistir(){}

DtAsistir::DtAsistir(string cod, int id){
    this->cod = cod;
    this->id = id;
}

string DtAsistir::getCodigo(){
    return this->cod;
}

int DtAsistir::getId(){
    return this->id;
}

ostream& operator << (ostream& salida, const DtAsistir& dta){
    cout << "Codigo de la Asignatura: " << dta.cod << endl;
    cout << "Id de la clase: " << dta.id << endl;
    return salida;
}

DtAsistir::~DtAsistir(){}