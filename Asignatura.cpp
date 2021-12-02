#include "Asignatura.h"
#include "Teorico.h"
#include "Practico.h"
#include "Monitoreo.h"

Asignatura:: Asignatura(){};

Asignatura:: Asignatura(string codigo, string nombre, DtInstanciaClase* tipoClases){
    this->codigo = codigo;
    this->nombre = nombre;
    this->tipoClases = tipoClases;
}

void Asignatura::setCodigo(string codigo){
    this->codigo = codigo;
}

void Asignatura::setNombre(string nombre){
    this->nombre = nombre;
}

string Asignatura::getCodigo(){
    return this->codigo;
}

string Asignatura::getNombre(){
    return this->nombre;
}

DtInstanciaClase* Asignatura::getTipoClases(){
    return this->tipoClases;
}


list<int> Asignatura::getClases(){
    map<int, Clase*> ::iterator it;
    list<int> retorno;
    for(it = clases.begin(); it != clases.end(); ++it){
        if((*it).second != NULL){
            retorno.push_back(it->first); 
        }
    }
    return retorno;
}
  
void Asignatura::agregarClase(Clase* clase){
    this->clases.insert(std::pair<int, Clase*>(clase->getId(), clase));
}

bool Asignatura::noTieneClases(){
    return clases.empty();
}

map<int, DtInfoClase*> Asignatura:: getDtInfoClase(){
	ManejadorClase* mC = ManejadorClase::getInstancia();
	map<int, Clase*>:: iterator it;
    map<int, DtInfoClase*> retorno;

	for (it = this->clases.begin(); it != this->clases.end(); ++it){
        if((*it).second != NULL){
            if(Teorico* t = dynamic_cast<Teorico*>((*it).second)){
            DtInfoTeorico* dtit = t->getDtInfoClase();
            retorno.insert(std::pair<int, DtInfoClase*>(dtit->getId(), dtit));

            }else if(Monitoreo* m = dynamic_cast<Monitoreo*>((*it).second)){
                DtInfoMonitoreo* dtim = m->getDtInfoClase();
                retorno.insert(std::pair<int, DtInfoClase*>(dtim->getId(), dtim));
                    
            }else if(Practico* p = dynamic_cast<Practico*>((*it).second)){
                DtInfoClase* dtic = p->getDtInfoClase();
                retorno.insert(std::pair<int, DtInfoClase*>(dtic->getId(), dtic));
            }
        }
        
	}

    return retorno;
}

Asignatura::~Asignatura(){
    delete tipoClases;
    ManejadorClase* mC= ManejadorClase::getInstancia();
    map<int, Clase*>::iterator it;
    for(it = this->clases.begin(); it != this->clases.end(); ++it){
        delete it->second;// segunda parte solucion error
        int id= it->first;// tambien
        mC->remove(id);
    }
    clases.clear();//tambien
}
