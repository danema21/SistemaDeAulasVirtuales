#include "DtLog.h"
        
DtLog::DtLog(){}

DtLog::DtLog(DtTimeStamp inicio, DtTimeStamp fin){
    this->inicio = inicio;
    this->fin = fin;
}

DtTimeStamp DtLog::getInicio(){
    return this->inicio;
}

DtTimeStamp DtLog::getFin(){
    return this->fin;
}

DtLog::~DtLog(){}