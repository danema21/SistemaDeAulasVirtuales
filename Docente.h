#ifndef DOCENTE_H
#define DOCENTE_H
#include <list>
#include "Perfil.h"
#include "Rol.h"

class Rol;


class Docente : public Perfil{
    private:
        string instituto;
        list <Rol*> roles;
    public:
        Docente();
        Docente(string,string,string,string,string);
        void setInstituto(string);
        string getInstituto();
        list<string> asignaturas();
        bool noDictaAsignatura(string); 
        void agregarAsignatura(Rol*);
        bool tieneMonitoreo(string);
        TipoRol decimeTuRol(string);
        void eliminarAsignatura(string);
        ~Docente();
};

#endif