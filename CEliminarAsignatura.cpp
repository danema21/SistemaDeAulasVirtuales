#include "CEliminarAsignatura.h"

CEliminarAsignatura::CEliminarAsignatura(){}

list<string> CEliminarAsignatura::listarAsignaturas(){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    return mA->listarAsignatura();
}

void CEliminarAsignatura::selectAsignatura(string cod){
    this->cod = cod;
}

void CEliminarAsignatura::eliminarAsignatura(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    map<string, Perfil*>::iterator it;
    map<string, Perfil*> listaP = mP->listarPerfiles();

    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a = mA->find(this->cod);

    for(it = listaP.begin(); it != listaP.end(); ++it){
        if(Estudiante* e = dynamic_cast<Estudiante*>((*it).second)){
            e->eliminarAsignatura(this->cod);
        }else if(Docente* d = dynamic_cast<Docente*>((*it).second)){
            d->eliminarAsignatura(this->cod);
        }
    }
    mA->destroy(a->getCodigo());
}

void CEliminarAsignatura::cancelar(){}

bool CEliminarAsignatura::existeAsignatura(string cod){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    return mA->existeAsignatura(cod);
}

CEliminarAsignatura::~CEliminarAsignatura(){}