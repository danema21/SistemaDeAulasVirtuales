#ifndef DTINFOTEORICO
#define DTINFOTEORICO
#include "DtInfoClase.h"
#include <string>
#include <list>

using namespace std;

class Docente;

class DtInfoTeorico: public DtInfoClase{

    private:
        int cantAsistentes;
    public:
        DtInfoTeorico();
        DtInfoTeorico(int, string, Docente*, int);
        int getCantAsistentes();
        ~DtInfoTeorico();

        friend ostream& operator << (ostream&, const DtInfoTeorico&);

};

#endif