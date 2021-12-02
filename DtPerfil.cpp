#include "DtPerfil.h"

DtPerfil::DtPerfil(){}

DtPerfil::DtPerfil(string nombre, string imagen_url, string email, string password){
    this->nombre = nombre;
    this->imagen_url = imagen_url;
    this->email = email;
    this->password = password;
}

string DtPerfil::getNombre(){
    return this->nombre;
}

string DtPerfil :: getImagen_url(){
    return this->imagen_url;
}

string DtPerfil ::getEmail(){
    return this->email;
}

string DtPerfil :: getPassword(){
    return this->password;
}

DtPerfil::~DtPerfil(){}