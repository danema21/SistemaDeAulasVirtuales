#include "Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(int cantAsistentes, int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    this->cantAsistentes = cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes){
    this->cantAsistentes = cantAsistentes;
}

int Teorico::getCantAsistentes(){
    return this->cantAsistentes;
}

DtInfoTeorico* Teorico::getDtInfoClase(){
	int cantidadA=0;
	list<AsisteEnVivo*>::iterator it2;
	list<AsisteEnVivo*> aux = this->getAsistentesEnVivo(); // chancla para el Dalto
		
	for (it2 = aux.begin(); it2 != aux.end(); it2++){
		if((*it2) != NULL){
			cantidadA++;
		}
	}
	DtInfoTeorico* retorno= new DtInfoTeorico(this->getId(), this->getNombre(), this->getDocente(), cantidadA);
	
	return retorno;
}

Teorico::~Teorico(){}