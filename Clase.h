#ifndef CLASE
#define CLASE
#include <string>
#include <map>
#include "DtTimeStamp.h"
#include "Docente.h"
#include "Participacion.h"
#include "AsisteEnVivo.h"
#include "AsisteDiferido.h"
#include "DtParticipacion.h"
#include "DtInfoClase.h"

using namespace std;

class Docente;
class AsisteEnVivo;
class AsisteDiferido;

class Clase{
    private:
        int id;
        string nombre;
        DtTimeStamp* inicio;
        DtTimeStamp* fin;
        string rutaVideo;
        static int idAutogenerado;
        Docente* docente;
        map<int, Participacion*> participaciones;
        list<AsisteEnVivo*> asistentesEnVivo;
        list<AsisteDiferido*> asistentesDiferido;
    public:
        Clase();
        Clase(int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*);
        void setId(int);
        int getId();
        void setNombre(string);
        string getNombre();
        void setInicio(DtTimeStamp*);
        DtTimeStamp* getInicio();
        void setFin(DtTimeStamp*);
        DtTimeStamp* getFin();
        void setRutaVideo(string);
        string getRutaVideo();
        void setDocente(Docente*);
        Docente* getDocente();
        static int getIdAutogenerado();
        void insertarAsistenciaEnVivo(AsisteEnVivo*);
        bool participaEstudiante(Estudiante*);
        list<DtParticipacion*> getParticipaciones();
        void addParticipacion(Participacion*);
        list<AsisteEnVivo*> getAsistentesEnVivo();
        Participacion* findParticipacion(int);

        virtual ~Clase();
};

#endif