#include "AsisteEnVivo.h"

AsisteEnVivo::AsisteEnVivo(){}
AsisteEnVivo::AsisteEnVivo(DtTimeStamp* inicio, DtTimeStamp* fin, Estudiante* estudiante){
    this->inicio = inicio;
    this->fin = fin;
    this->estudiante = estudiante;
}

void AsisteEnVivo::setInicio(DtTimeStamp* inicio){
    this->inicio = inicio;
}
DtTimeStamp* AsisteEnVivo::getInicio(){
    return this->inicio;
}

void AsisteEnVivo::setFin(DtTimeStamp* fin){
    this->fin = fin;
}
DtTimeStamp* AsisteEnVivo::getFin(){
    return this->fin;
}

void AsisteEnVivo::setEstudiante(Estudiante* estudiante){
    this->estudiante = estudiante;
}
Estudiante* AsisteEnVivo::getEstudiante(){
    return this->estudiante;
}

AsisteEnVivo::~AsisteEnVivo(){}