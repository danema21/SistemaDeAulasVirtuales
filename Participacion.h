#ifndef PARTICIPACION
#define PARTICIPACION
#include <string>
#include "DtTimeStamp.h"
#include "Perfil.h"
#include "DtParticipacion.h"

using namespace std;

class Participacion{
    private:
        int id;
        DtTimeStamp* fecha;
        string mensaje;
        Participacion* enRespuestaA;
        Perfil* perfil;
        static int idAutogenerado;
    public:
        Participacion();
        Participacion(int, DtTimeStamp*, string, Participacion*, Perfil*);
        void setId(int);
        int getId();
        void setFecha(DtTimeStamp*);
        DtTimeStamp* getFecha();
        void setMensaje(string);
        string getMensaje();
        void setEnRespuestaA(Participacion*);
        DtParticipacion* getDtRespuesta();
        Participacion* getEnRespuestaA();
        void setPerfil(Perfil*);
        Perfil* getPerfil();
        static int getIdAutogenerado();
        ~Participacion();
};

#endif