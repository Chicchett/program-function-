#include <stdio.h>
#include "input.h"
#include "bisestile.h"



int main(){

    int anno;
    int bisestile;
     
    anno = leggiAnno();
    bisestile = verificaBisestile(anno);
    if(bisestile == 1){
        printf("Anno %d è bisestile\n", anno);
    }else {
        printf("Anno %d non è bisestile\n", anno);
    }

    return 0;
}