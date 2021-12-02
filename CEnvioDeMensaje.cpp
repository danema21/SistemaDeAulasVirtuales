#include "CEnvioDeMensaje.h"
#include <ctime>
//#include <iostream>
//#include <stdio.h>
//#include <time.h>  


int CEnvioDeMensaje::idp = 0;

CEnvioDeMensaje::CEnvioDeMensaje(){}

DtTimeStamp* CEnvioDeMensaje:: cargarFecha(){
    time_t now = time(0);
    tm * Time = localtime(&now);
    DtFecha* fecha = new DtFecha(Time->tm_mday,Time->tm_mon, 1900+Time->tm_year);    
    DtTimeStamp* Actual = new DtTimeStamp(fecha,Time->tm_hour, Time->tm_min, Time->tm_sec);
    
    return Actual;
}

void CEnvioDeMensaje::verificarPerfil(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    this->perfil = mP->find(email);

}

list<int> CEnvioDeMensaje::clasesOnLineAsistiendo(){
    ManejadorClase* mC = ManejadorClase::getInstancia();
    map<int, Clase*>::iterator it;
    map<int, Clase*> listaC = mC->obtenerClases();
    list<int> retorno;

    if(Docente* d = dynamic_cast<Docente*>(this->perfil)){
        for(it = listaC.begin();it != listaC.end(); ++it){
            if(it->second->getDocente()==d)
                retorno.push_back(it->first);
        }

    }
    else if(Estudiante* e = dynamic_cast<Estudiante*>(this->perfil)){
        for(it = listaC.begin();it != listaC.end(); ++it){
            if(it->second->participaEstudiante(e))
                retorno.push_back(it->first);
        }
    }

    return retorno;
}

list<DtParticipacion*> CEnvioDeMensaje::selectClase(int id){
    this->id = id;

    ManejadorClase* mC = ManejadorClase::getInstancia();
    Clase* c = mC->find(id);
    
    return c->getParticipaciones(); //para hablar con el seba
}

void CEnvioDeMensaje::responder(int idp){
    this->idp = idp;
}

void CEnvioDeMensaje::ingresarTexto(string txt){
    this->txt = txt;
}

void CEnvioDeMensaje::enviarMensaje(){
    ManejadorClase* mC = ManejadorClase::getInstancia();
    Clase* c = mC->find(id);
    DtTimeStamp* fecha = CEnvioDeMensaje::cargarFecha();
    Participacion* rp = NULL; // <-- Buscar participacion -_-
    if(idp != 0){
        rp = c->findParticipacion(idp);
    } 
    Participacion* p = new Participacion(id, fecha, txt, rp, perfil);
    c->addParticipacion(p);
    this->idp = 0;
}

void CEnvioDeMensaje::cancelar(){

    //liberar memoria dinamica.
}

CEnvioDeMensaje::~CEnvioDeMensaje(){}