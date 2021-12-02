#ifndef DTASISTIR
#define DTASISTIR
#include <string>
#include <iostream>

using namespace std;

class DtAsistir{
    private:
        string cod;
        int id;
    public:
        DtAsistir();
        DtAsistir(string, int);
        string getCodigo();
        int getId();
        ~DtAsistir();

        friend ostream& operator << (ostream&, const DtAsistir&);
};

#endif