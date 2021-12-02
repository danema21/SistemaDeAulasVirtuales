#ifndef ICENVIODEMENSAJE
#define ICENVIODEMENSAJE
#include "DtParticipacion.h"
#include <list>
#include <map>
#include <string>

using namespace std;

class ICEnvioDeMensaje{
    public:
        virtual void verificarPerfil(string)=0;
        virtual list<int> clasesOnLineAsistiendo()=0;
        virtual list<DtParticipacion*> selectClase(int)=0;
        virtual void responder(int)=0;
        virtual void ingresarTexto(string)=0;
        virtual void enviarMensaje()=0;
        virtual DtTimeStamp* cargarFecha()=0;
        virtual void cancelar()=0;

};

#endif