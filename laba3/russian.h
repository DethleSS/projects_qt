#ifndef RUSSIAN_H
#define RUSSIAN_H

#include <iostream.h>
ostream& operator<<(ostream &stream,char* s){
    for(char* ps=s; *ps; ps++){
        if(*ps=='ё')
            stream<<char(241);
        else if(*ps=='Ё')
            stream<<char(240);
        else if(*ps>=-64 && *ps<=-17)
            stream<<char(*ps+64+128);
        else if(*ps<0)
            stream<<char(*ps+64+176);
        else
            stream<<*ps;
    }
    return stream;
}

#endif // RUSSIAN_H
