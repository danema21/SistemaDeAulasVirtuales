#include "Fabrica.h"

ICAltaUsuario* Fabrica::getCAltaUsuario(){
    CAltaUsuario* cau = new CAltaUsuario();
    return cau;
}

ICAltaAsignatura* Fabrica::getCAltaAsignatura(){
    CAltaAsignatura* caa = new CAltaAsignatura();
    return caa;
}

ICAsistenciaAClaseEnVivo* Fabrica::getCAsistenciaAClaseEnVivo(){
    CAsistenciaAClaseEnVivo* caacen = new CAsistenciaAClaseEnVivo();
    return caacen;
}

ICAsignarAsignaturaDocente* Fabrica::getCAsignarAsignaturaDocente(){
    CAsignarAsignaturaDocente* caad = new CAsignarAsignaturaDocente();
    return caad;
}

ICEliminarAsignatura* Fabrica::getCEliminarAsignatura(){
    CEliminarAsignatura* cea = new CEliminarAsignatura();
    return cea;
}

ICInicioClase* Fabrica::getCInicioClase(){
    CInicioClase* cic= new CInicioClase();
    return cic;
}

ICInscripcionAsignatura* Fabrica::getCInscripcionAsignatura(){
    CInscripcionAsignatura* cia= new CInscripcionAsignatura();
    return cia;
}

ICEnvioDeMensaje* Fabrica::getCEnvioDeMensaje(){
    CEnvioDeMensaje* cem = new CEnvioDeMensaje();
    return cem;
}

ICListadoClases* Fabrica::getCListadoClases(){
    CListadoClases* clc = new CListadoClases();
    return clc;
}
