#include "Perfil.h"

Perfil::Perfil(){}

Perfil::Perfil(string nombre, string imagen_url, string email, string password){
    this->nombre = nombre;
    this->imagen_url = imagen_url;
    this->email = email;
    this->password = password;
}

void Perfil::setNombre(string nombre){
    this->nombre = nombre;
}
string Perfil::getNombre(){
    return this->nombre;
}

void Perfil :: setImagen_url(string imagen_url){
    this->imagen_url = imagen_url;
}

string Perfil :: getImagen_url(){
    return this->imagen_url;
}

void Perfil::setEmail(string email){
    this->email = email;
}
string Perfil ::getEmail(){
    return this->email;
}

void Perfil :: setPassword(string password){
    this->password = password;
}
string Perfil :: getPassword(){
    return this->password;
}

Perfil::~Perfil(){}