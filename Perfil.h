#ifndef PERFIL
#define PERFIL
#include <iostream>
#include <string>

using namespace std;

class Perfil{
    private:
        string nombre;
        string imagen_url;
        string email;
        string password;
    public:
        Perfil();
        Perfil(string, string, string, string);
        
        void setNombre(string);
        string getNombre();

        void setImagen_url(string);
        string getImagen_url();

        void setEmail(string);
        string getEmail();
        
        void setPassword(string);
        string getPassword();

        virtual ~Perfil();

};        
    
#endif