#ifndef CALTAUSUARIO
#define CALTAUSUARIO
#include "TipoPerfil.h"
#include "DtPerfil.h"
#include "ManejadorPerfil.h"
#include "Perfil.h"
#include "Estudiante.h"
#include "Docente.h"
#include "ICAltaUsuario.h"

class CAltaUsuario : public ICAltaUsuario{
    private:
        DtPerfil* datosUsuario;
        TipoPerfil tipoPerfil;
        string doc;
        string inst;
        string email;
    public:
        CAltaUsuario();
        void ingresarDatosPerfil(DtPerfil*);
        void ingresarEstudiante(string);
        void ingresarDocente(string);
        void altaUsuario();
        ~CAltaUsuario();

        bool existeUsuario(string);
        void cancelar();
};

#endif