#include "CAsistenciaAClaseEnVivo.h"
#include "ManejadorPerfil.h"
#include "ManejadorAsignatura.h"
#include "ManejadorClase.h"
#include "Estudiante.h"
#include <chrono>
#include <ctime>
#include <time.h>

CAsistenciaAClaseEnVivo::CAsistenciaAClaseEnVivo(){}

list<string> CAsistenciaAClaseEnVivo::asignaturasInscripto(string email){
    this->email = email;
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);
    return e->asignaturaInscriptas();
}

list<int> CAsistenciaAClaseEnVivo::clasesOnlineDisponibles(string cod){
    this->cod = cod;
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a = mA->find(cod);
    return a->getClases();
}

DtAsistir* CAsistenciaAClaseEnVivo::selectClase(int id){
    this->id = id;
    DtAsistir* dta = new DtAsistir(this->cod, this->id);
    return dta;
}

void CAsistenciaAClaseEnVivo::asistirClaseEnVivo(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);//chancletaZo para Ramos@aguas
    Estudiante* e = dynamic_cast<Estudiante*>(p);

    time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time. 
    struct tm* tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo 

    char hora[30]; 
    strftime(hora,30,"%H",tlocal); 

    char minuto[30]; 
    strftime(minuto,30,"%M",tlocal); 

    char segundo[30]; 
    strftime(segundo,30,"%S",tlocal);

    char dia[30]; 
    strftime(dia,30,"%d",tlocal); 

    char mes[30]; 
    strftime(mes,30,"%m",tlocal); 

    char anio[30]; 
    strftime(anio,30,"%Y",tlocal);

    int hora2= atoi(hora);
    int minuto2= atoi(minuto);
    int segundo2= atoi(segundo);

    int dia2= atoi(dia);
    int mes2= atoi(mes);
    int anio2= atoi(anio);

    DtFecha* dtf = new DtFecha(dia2, mes2, anio2);
    DtTimeStamp* dtsInicio = new DtTimeStamp(dtf, hora2, minuto2, segundo2);

    AsisteEnVivo* aev = new AsisteEnVivo(dtsInicio, NULL, e);

    ManejadorClase* mC = ManejadorClase::getInstancia();
    Clase* c = mC->find(id);

    c->insertarAsistenciaEnVivo(aev);
    
}

void CAsistenciaAClaseEnVivo::cancelar(){

}

bool CAsistenciaAClaseEnVivo::existeUsuario(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    return mP->existePerfil(email);
}

bool CAsistenciaAClaseEnVivo::esEstudiante(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    if(p != NULL){
        if(dynamic_cast<Estudiante*>(p))
            return true;
        else
            return false;
    }else{
        cout << "No existen Perfiles" << endl;
        return false;
    }
    
}

bool CAsistenciaAClaseEnVivo::existeAsignatura(string codigo){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    return mA->existeAsignatura(codigo);
}

bool CAsistenciaAClaseEnVivo::existeClase(int id){
    ManejadorClase* mC = ManejadorClase::getInstancia();
    return mC->existeClase(id);
}

bool CAsistenciaAClaseEnVivo::perfilesVacio(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    return mP->estaVacio();
}

bool CAsistenciaAClaseEnVivo::asignaturasVacio(){
    ManejadorPerfil* mA = ManejadorPerfil::getInstancia();
    return mA->estaVacio();
}

bool CAsistenciaAClaseEnVivo::clasesVacio(){
    ManejadorPerfil* mC = ManejadorPerfil::getInstancia();
    return mC->estaVacio();
}

bool CAsistenciaAClaseEnVivo::asignaturaNoTieneClases(string cod){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    if(Asignatura* a = mA->find(cod)){
        return a->noTieneClases();
    }
    else{
        return false;
    }
}

bool CAsistenciaAClaseEnVivo::estaInscripto(string email, string codAsig){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);

    bool encontrado = false;
    list<string> aux = e->asignaturaInscriptas();
    list<string>::iterator it = aux.begin();
    
    while(it != aux.end() && !encontrado){
        if((*it) == codAsig){
            encontrado = true;
        }
        ++it;
    }
    return encontrado;
}

CAsistenciaAClaseEnVivo::~CAsistenciaAClaseEnVivo(){}