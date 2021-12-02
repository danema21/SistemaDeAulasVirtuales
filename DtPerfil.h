#ifndef DTPERFIL
#define DTPERFIL
#include <iostream>
#include <string>

using namespace std;

class DtPerfil{
    private:
        string nombre;
        string imagen_url;
        string email;
        string password;
    public:
        DtPerfil();
        DtPerfil(string, string, string, string);
    
        string getNombre();
        string getImagen_url();
        string getEmail();
        string getPassword();

        virtual ~DtPerfil();

};        
    
#endif