#include "CListadoClases.h"

CListadoClases::CListadoClases(){}

list<string> CListadoClases::asignaturasAsignadas(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    list<string> retorno;

    if(Docente* d = dynamic_cast<Docente*>(p)){
        retorno = d->asignaturas();
    }
    return retorno;
}

map<int,DtInfoClase*> CListadoClases::selectAsignatura(string cod){
	ManejadorAsignatura* mA= ManejadorAsignatura :: getInstancia();
	Asignatura* a = mA->find(cod);
    return a->getDtInfoClase();
}