#include "Docente.h"

Docente::Docente(){}
Docente::Docente(string nombre, string imagen_url, string email, string password, string instituto): 
                 Perfil(nombre, imagen_url, email, password){
    this->instituto = instituto;
}

void Docente::setInstituto(string instituto){
    this->instituto = instituto;
}

string Docente::getInstituto(){
    return this->instituto;
}

list<string> Docente::asignaturas(){
    list<Rol*>:: iterator it;
    list<string> retorno;
    for(it= this->roles.begin(); it!=this->roles.end(); it++){
        if((*it)->getAsignatura() != NULL){
            string cod = (*it)->getCodigoAsignatura();
            retorno.push_back(cod);
        }
    }
    return retorno;
}

bool Docente::noDictaAsignatura(string cod){
    list<Rol*>::iterator it;
    bool aux=true;

    for(it= this->roles.begin(); it != this->roles.end();++it){// al parecer los roles estan vacios y por eso no entra al for
        if((*it)->getAsignatura() != NULL){//si no controlamos esto cuando se aga el get y lo compare con el cod al ser NULL peta
            if((*it)->getCodigoAsignatura()==cod){
                aux=false;
            }
        }
    }
    return aux;
}

bool Docente::tieneMonitoreo(string codigo){
    bool retorno = false;
    list<Rol*>:: iterator it;
    for(it= this->roles.begin(); it!=this->roles.end(); it++){
        if((*it)->getAsignatura() != NULL){
            string cod = (*it)->getCodigoAsignatura();
            if(cod == codigo){
                if((*it)->getTipo() == MONITOREO){
                    retorno = true;
                }
            }
        }
    }
    return retorno;
}


void Docente::agregarAsignatura(Rol* rol){
    this->roles.push_back(rol);
}

TipoRol Docente::decimeTuRol(string cod){
    list<Rol*>::iterator it=roles.begin();
    bool encontre=false;
    TipoRol retorno;
    while(it!=roles.end() && !encontre){
        if((*it)->getAsignatura() != NULL){
            if((*it)->getCodigoAsignatura()==cod){
                retorno=(*it)->getTipo();
                encontre=true;
            }
        }
        it++;
    }
    return retorno;
}

void Docente::eliminarAsignatura(string cod){
    //roles.remove();
    list<Rol*>::iterator it;
    for(it = roles.begin(); it != roles.end(); ++it){// no entra al for
        if((*it)->getAsignatura() != NULL){ //NULL->getAsignatura() no existe, chausito segmentation fault :)
            bool esA = (*it)->esAsignatura(cod);
            if(esA){
                // delete *it; //borro el puntero pero nunca elimino el elemento de la lista
                (*it)->eliminarAsignatura();
                //roles.remove(*it);// al hacer la seguna vuelta muere
            }
        }
    }
}

Docente::~Docente(){}