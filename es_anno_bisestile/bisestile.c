#include <stdio.h>
#include <stdlib.h>

#define SECOLARE 100
#define BASE 4
#define ECCEZIONE 400


int verificaBisestile(int anno){

    int bisestile; 

    if(anno % ECCEZIONE == 0){
        bisestile = 1;
    } else if(anno % SECOLARE == 0){
        bisestile = 0;
    }else if(anno % BASE == 0){
        bisestile = 1;
    } else {
        bisestile = 0;
    }
}