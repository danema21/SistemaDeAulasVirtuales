#include "Monitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(int id, string nombre, DtTimeStamp* inicio,  DtTimeStamp* fin, string rutaVideo, Docente* docente, list<string> estudiantesList) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    list<string>::iterator it;
    for(it = estudiantesList.begin(); it != estudiantesList.end(); it++){
        Estudiante* e = dynamic_cast<Estudiante*>(mP->find(*it));
        estudiantes.insert(std::pair<string, Estudiante*>(e->getEmail(), e));
    }
}

DtInfoMonitoreo* Monitoreo:: getDtInfoClase(){
	map<string, Estudiante*>::iterator it1;
	DtInfoMonitoreo* retorno = new DtInfoMonitoreo(this->getId(), this->getNombre(), this->getDocente());

	for (it1 = this->estudiantes.begin(); it1 != this->estudiantes.end(); it1++){
		retorno->agregarEstudiante((*it1).second->getEmail());
	}
	return retorno;
}

Monitoreo::~Monitoreo(){}