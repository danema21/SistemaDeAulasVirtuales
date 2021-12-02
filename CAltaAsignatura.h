#ifndef CALTAASIGNATURA
#define CALTAASIGNATURA
#include "ICAltaAsignatura.h"
#include "DtAsignatura.h"

class CAltaAsignatura : public ICAltaAsignatura{
    private:
        DtAsignatura* datosAsignatura;
    public:
        CAltaAsignatura();
        DtAsignatura* ingresar(DtAsignatura*);
        void altaAsignatura();
        void cancelar();

        bool existeAsignatura(string);
        
        ~CAltaAsignatura();
};

#endif