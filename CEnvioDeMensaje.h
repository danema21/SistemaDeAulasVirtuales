#ifndef CENVIODEMENSAJE
#define CENVIODEMENSAJE
#include "ICEnvioDeMensaje.h"
#include "ManejadorPerfil.h"
#include "ManejadorClase.h"

class CEnvioDeMensaje : public ICEnvioDeMensaje{
    private:
        int id; // de la Clase
        static int idp; // por si quiere ser una respuesta
        string txt; // texto del mensaje
        Perfil* perfil; // perfil asociado
    public:
        CEnvioDeMensaje();
        void verificarPerfil(string);   
        list<int> clasesOnLineAsistiendo();
        list<DtParticipacion*> selectClase(int);
        void responder(int);
        void ingresarTexto(string);
        void enviarMensaje();
        void cancelar();
        DtTimeStamp* cargarFecha();
        ~CEnvioDeMensaje();

};

#endif