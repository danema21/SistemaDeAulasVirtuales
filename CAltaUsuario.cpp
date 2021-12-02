#include "CAltaUsuario.h"
#include "ManejadorPerfil.h"

CAltaUsuario::CAltaUsuario(){}

void CAltaUsuario::ingresarDatosPerfil(DtPerfil* datosUsuario){
    this->datosUsuario = datosUsuario;
}

void CAltaUsuario::ingresarEstudiante(string doc){
    this->doc = doc;
    this->tipoPerfil = ESTUDIANTE;
}

void CAltaUsuario::ingresarDocente(string inst){
    this->inst = inst;
    this->tipoPerfil = DOCENTE;
}

void CAltaUsuario::altaUsuario(){
   ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
   
   if(tipoPerfil==ESTUDIANTE){
       Estudiante* e=new Estudiante(datosUsuario->getNombre(), datosUsuario->getImagen_url(), 
                                    datosUsuario->getEmail(), datosUsuario->getPassword(), doc);
       mP->add(e);
   } 
   else if(tipoPerfil==DOCENTE){
       Docente* d=new Docente(datosUsuario->getNombre(), datosUsuario->getImagen_url(),
                              datosUsuario->getEmail(), datosUsuario->getPassword(), inst);
       mP->add(d);
   }
}

CAltaUsuario::~CAltaUsuario(){}

bool CAltaUsuario::existeUsuario(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    return mP->existePerfil(email);
}

void CAltaUsuario::cancelar(){
    delete datosUsuario;//si no la gana la empata - chancla
}