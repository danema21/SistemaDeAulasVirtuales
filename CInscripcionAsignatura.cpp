#include "CInscripcionAsignatura.h"

CInscripcionAsignatura::CInscripcionAsignatura(){}

list<string> CInscripcionAsignatura::asignaturasNoInscripto(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    list<string> retorno;
    if(Estudiante* e = dynamic_cast<Estudiante*>(p)){

        map<string, Asignatura*> asignaturasEstudiante = e->getAsignaturas();

        ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
        map<string, Asignatura*> asignaturas = mA->getAsignaturas();

        
        map<string, Asignatura*>::iterator it1;
        map<string, Asignatura*>::iterator it2;
        for(it1 = asignaturas.begin(); it1 != asignaturas.end(); it1++){
            bool repetido = false;
            for(it2 = asignaturasEstudiante.begin(); it2 != asignaturasEstudiante.end(); it2++){
                if(it1->first == it2->first){
                    repetido == true;
                }
            }
            if(!repetido){
                retorno.push_back(it1->first);
            }
        }
    }
    return retorno;
}

void CInscripcionAsignatura::selectAsignatura(string codigo){
    this->codigo = codigo;
}

void CInscripcionAsignatura::inscribir(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);

    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a = mA->find(this->codigo);
    
    e->agregarAsignatura(a);
}

bool CInscripcionAsignatura::perfilesVacio(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    return mP->estaVacio();
}

bool CInscripcionAsignatura::asignaturasVacio(){
    ManejadorPerfil* mA = ManejadorPerfil::getInstancia();
    return mA->estaVacio();
}

bool CInscripcionAsignatura::clasesVacio(){
    ManejadorPerfil* mC = ManejadorPerfil::getInstancia();
    return mC->estaVacio();
}
        
CInscripcionAsignatura::~CInscripcionAsignatura(){}