
#include "Estudiante.h"
#include "ManejadorAsignatura.h"

Estudiante::Estudiante(){}
Estudiante::Estudiante(string nombre ,string imagen_url ,string email ,string password, string documento)
                        :Perfil(nombre,imagen_url,email,password){
    this->documento = documento;
}
void Estudiante::setDocumento(string documento){
    this->documento = documento;
}
string Estudiante:: getDocumento(){
    return this->documento;
}

map<string, Asignatura*> Estudiante::getAsignaturas(){
    map<string, Asignatura*>:: iterator it;
    map<string, Asignatura*> retorno;
    for(it= this->asignaturas.begin(); it!=this->asignaturas.end(); it++){
        retorno.insert(std::pair<string, Asignatura*>(it->first, it->second));
    }
    return retorno;
}

bool Estudiante::estaInscripto(string codigo){
    map<string, Asignatura*>::iterator it;
    return this->asignaturas.find(codigo) != this->asignaturas.end();
}

void Estudiante::agregarAsignatura(Asignatura* asignatura){
    this->asignaturas.insert(std::pair<string, Asignatura*>(asignatura->getCodigo(), asignatura));
}

void Estudiante :: eliminarAsignatura(string cod){

    asignaturas.erase(cod);
}

list<string> Estudiante::asignaturaInscriptas(){
    map<string, Asignatura*>::iterator it;
    list<string> retorno;
    for(it = asignaturas.begin(); it != asignaturas.end(); ++it){
        if((*it).second != NULL){
            retorno.push_back(it->first);
        }
    }
    return retorno;
}

Estudiante::~Estudiante(){}