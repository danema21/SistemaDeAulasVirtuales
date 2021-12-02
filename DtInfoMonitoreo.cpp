#include "DtInfoMonitoreo.h"

DtInfoMonitoreo::DtInfoMonitoreo(){}

DtInfoMonitoreo::DtInfoMonitoreo(int id, string nombre, Docente* docente):DtInfoClase(id, nombre, docente){}

void DtInfoMonitoreo:: agregarEstudiante(string email){
	this->estudiantes.push_back(email);
}

ostream& operator << (ostream& salida, DtInfoMonitoreo& dtim){
    list<string>::iterator it;
    salida << "Estudiantes habilitados:" << endl;
    for(it = dtim.estudiantes.begin(); it != dtim.estudiantes.end(); it++){
		salida << *it << endl;
    }
    return salida;
}

DtInfoMonitoreo::~DtInfoMonitoreo(){}