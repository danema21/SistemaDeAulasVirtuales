#include "Participacion.h"

int Participacion:: idAutogenerado = 1;

int Participacion:: getIdAutogenerado(){
    return idAutogenerado;
}

Participacion::Participacion(){}

Participacion::Participacion(int id, DtTimeStamp* fecha, string mensaje, Participacion* enRespuestaA, Perfil* perfil){
    this->id = idAutogenerado;
    idAutogenerado ++;
    this->fecha = fecha;
    this->mensaje = mensaje;
    this->enRespuestaA = enRespuestaA;
    this->perfil = perfil;
}

void Participacion::setId(int id){
    this->id = id;
}

int Participacion::getId(){
    return this->id;
}

void Participacion::setFecha(DtTimeStamp* fecha){
    this->fecha = fecha;
}
DtTimeStamp* Participacion::getFecha(){
    return this->fecha;
}

void Participacion::setMensaje(string mensaje){
    this->mensaje = mensaje;
}
string Participacion::getMensaje(){
    return this->mensaje;
}
void Participacion::setEnRespuestaA(Participacion* enRespuestaA){
    this->enRespuestaA = enRespuestaA;
}

Participacion* Participacion::getEnRespuestaA(){
    return this->enRespuestaA;
}

void Participacion::setPerfil(Perfil* perfil){
    this->perfil = perfil;
}

Perfil* Participacion::getPerfil(){
    return this->perfil;
}

DtParticipacion* Participacion:: getDtRespuesta(){
        DtParticipacion* dtp = new DtParticipacion (enRespuestaA->getId(),
                                                    enRespuestaA->getFecha(), 
                                                    enRespuestaA->getMensaje(),
                                                    NULL);
        return dtp;
}

Participacion::~Participacion(){}