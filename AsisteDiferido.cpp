#include "AsisteDiferido.h"

AsisteDiferido::AsisteDiferido(){}

AsisteDiferido::AsisteDiferido(Estudiante* estudiante){
    this->estudiante = estudiante;
}

void AsisteDiferido::setEstudiante(Estudiante* estudiante){
    this->estudiante = estudiante;
}

Estudiante* AsisteDiferido::getEstudiante(){
    return this->estudiante;
}

AsisteDiferido::~AsisteDiferido(){}