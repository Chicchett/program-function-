#include <stdio.h>
#include <stdlib.h>


static void clearBuffer(void){ //non ci interessa vederla anche all'esterno
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int leggiAnno(void){

    int controllo;
    int anno;
    int continua;

    do{
        printf("inserisci anno: \n");
        controllo = scanf("%d", &anno);
        if(controllo != 1){
            printf("Errore, stai inserendo un valore non valido\n");
            clearBuffer();
        }else if(anno < 0){
            printf("Errore, non stai inserendo un numero di ore valido\n");
            continua = 1;
        }
    }while(continua == 1 || anno < 10);

    return anno;
}