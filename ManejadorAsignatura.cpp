#include "ManejadorAsignatura.h"

ManejadorAsignatura::ManejadorAsignatura(){}

ManejadorAsignatura* ManejadorAsignatura::instancia = NULL;

void ManejadorAsignatura::add(Asignatura* asignatura){
    asignaturas.insert(std::pair<string, Asignatura*>(asignatura->getCodigo(), asignatura));
}

Asignatura* ManejadorAsignatura::find(string codigo){
    map<string, Asignatura*>::iterator it;
    it = asignaturas.find(codigo);
    return it->second;
}

ManejadorAsignatura* ManejadorAsignatura::getInstancia(){
        if(instancia == NULL){
        instancia = new ManejadorAsignatura();
    }
    return instancia;
}
bool ManejadorAsignatura::existeAsignatura(string codigo){
    map<string, Asignatura*>::iterator it;
    return this->asignaturas.find(codigo) != this->asignaturas.end();    
}

list<string> ManejadorAsignatura::listarAsignatura(){
    list<string> aux;
    for(map<string,Asignatura*>::iterator it = this->asignaturas.begin(); it != this->asignaturas.end(); it++)
        aux.push_back(it->first);
    return aux;
}

map<string, Asignatura*> ManejadorAsignatura::getAsignaturas(){
    map<string, Asignatura*> retorno;
    map<string, Asignatura*>::iterator it;
    for(it = asignaturas.begin(); it != asignaturas.end(); it++){
        retorno.insert(std::pair<string, Asignatura*>(it->first, it->second));
    }
    return retorno;
}

ManejadorAsignatura::~ManejadorAsignatura(){}

bool ManejadorAsignatura::estaVacio(){
    return this->asignaturas.empty();
}

void ManejadorAsignatura::destroy(string cod){
    //habria que destruir la clase y las participaciones, y los asiste en vivo y diferido
    Asignatura* a = asignaturas.find(cod)->second;
    a->~Asignatura();// solucion al error
    asignaturas.erase(cod);
}

