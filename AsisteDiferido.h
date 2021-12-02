#ifndef ASISTEDIFERIDO
#define ASISTEDIFERIDO
#include "Estudiante.h"
#include "DtLog.h"

class Estudiante;

class AsisteDiferido{
	private:
		list<DtLog*> acceso;
		Estudiante* estudiante;
	public:
		AsisteDiferido();
		AsisteDiferido(Estudiante*);
		void setEstudiante(Estudiante*);
		Estudiante* getEstudiante();

		~AsisteDiferido();
};

#endif