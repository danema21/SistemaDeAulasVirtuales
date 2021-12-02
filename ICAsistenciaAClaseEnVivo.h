#ifndef ICASISTENCIAACLASEENVIVO
#define ICASISTENCIAACLASEENVIVO
#include <list>
#include "DtAsistir.h"

class ICAsistenciaAClaseEnVivo{
    public:
        virtual list<string> asignaturasInscripto(string)=0;
        virtual list<int> clasesOnlineDisponibles(string)=0;
        virtual DtAsistir* selectClase(int)=0;
        virtual void asistirClaseEnVivo()=0;
        virtual void cancelar()=0;

        virtual bool existeUsuario(string)=0;
        virtual bool esEstudiante(string)=0;
        virtual bool existeAsignatura(string)=0;
        virtual bool existeClase(int)=0;

        virtual bool perfilesVacio()=0;
        virtual bool asignaturasVacio()=0;
        virtual bool clasesVacio()=0;
        virtual bool asignaturaNoTieneClases(string)=0;
        virtual bool estaInscripto(string, string)=0;

};

#endif