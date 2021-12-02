#include "Clase.h"

Clase::Clase(){}

int Clase:: idAutogenerado = 1;

int Clase:: getIdAutogenerado(){
    return idAutogenerado;
}

Clase::Clase(int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente){
    this->id = idAutogenerado;
    idAutogenerado++;
    this->nombre = nombre;
    this-> inicio = inicio;
    this->fin = fin;
    this->rutaVideo = rutaVideo;
    this->docente = docente;
}

void Clase::setId(int id){
    this->id = id;
}

int Clase::getId(){
    return this->id;
}

void Clase::setNombre(string nombre){
    this->nombre = nombre;
}

string Clase::getNombre(){
    return this->nombre;
}

void Clase::setInicio(DtTimeStamp* inicio){
    this->inicio = inicio;
}

DtTimeStamp* Clase::getInicio(){
    return this->inicio;
}

void Clase::setFin(DtTimeStamp* fin){
    this->fin = fin;
}

DtTimeStamp* Clase::getFin(){
    return this->fin;
}

void Clase::setRutaVideo(string rutaVideo){
    this->rutaVideo = rutaVideo;
}

string Clase::getRutaVideo(){
    return this->rutaVideo;
}

void Clase::setDocente(Docente* docente){
    this->docente = docente;
}

Docente* Clase::getDocente(){
    return this->docente;
}

void Clase::insertarAsistenciaEnVivo(AsisteEnVivo* aev){
    asistentesEnVivo.push_back(aev);
}

list<AsisteEnVivo*> Clase:: getAsistentesEnVivo(){
    return this->asistentesEnVivo;
}

bool Clase::participaEstudiante(Estudiante* est){
    bool retorno = false;
    list<AsisteEnVivo*>::iterator it = asistentesEnVivo.begin();

    while(!retorno && (it != asistentesEnVivo.end())){
        if((*it)!= NULL){
            if((*it)->getEstudiante() == est)
                retorno = true;
        }
        it++;
    }
    return retorno;
}
void Clase::addParticipacion(Participacion* p){
    participaciones.insert(std::pair<int,Participacion*>(p->getId(),p));
}

list<DtParticipacion*> Clase::getParticipaciones(){
    list<DtParticipacion*> retorno;
    map<int,Participacion*>::iterator it;

    for(it=participaciones.begin(); it != participaciones.end(); ++it ){
        if((*it).second->getEnRespuestaA() != NULL){
            DtParticipacion* dtp = new DtParticipacion(it->second->getId(),
                                                       it->second->getFecha(), 
                                                       it->second->getMensaje(),
                                                       it->second->getDtRespuesta());
            retorno.push_back(dtp);
        }else{
            DtParticipacion* dtrp = NULL;
            DtParticipacion* dtp = new DtParticipacion(it->second->getId(),
                                                       it->second->getFecha(), 
                                                       it->second->getMensaje(),
                                                       dtrp);
            retorno.push_back(dtp);
        }
        
    }
    return retorno;
}

Participacion* Clase::findParticipacion(int idp){
    return participaciones.find(idp)->second;
}

Clase::~Clase(){
    this->participaciones.clear();
    this->asistentesEnVivo.clear(); 
    this->asistentesDiferido.clear();
    
}