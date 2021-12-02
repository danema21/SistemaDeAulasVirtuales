#include "ManejadorClase.h"

ManejadorClase* ManejadorClase::instancia = NULL;

ManejadorClase::ManejadorClase(){}

void ManejadorClase::add(Clase* clase){
    clases.insert(std::pair<int, Clase*>(clase->getId(), clase));
}

Clase* ManejadorClase::find(int id){ // cambie el argumento que era un string por un int, ya que al usar map las clases se identifican por la id
    map<int, Clase*>::iterator it;
    it = clases.find(id);
    return it->second;
}

ManejadorClase* ManejadorClase::getInstancia(){
    if(instancia == NULL){
        instancia = new ManejadorClase();
    }
    return instancia;
}

bool ManejadorClase::existeClase(int id){ // cambie el argumento que era un string por un int, ya que al usar map las clases se identifican por la id
    map<int, Clase*>::iterator it;
    return this->clases.find(id) != this->clases.end();
}
bool ManejadorClase::estaVacio(){
    return clases.empty();
}

map<int, Clase*> ManejadorClase::obtenerClases(){
    return clases;
}

void ManejadorClase::remove(int id){
    map<int, Clase*>::iterator it = clases.find(id);
    this->clases.erase(it);//tercer parte solucion
}

ManejadorClase::~ManejadorClase(){}