#include <stdio.h>
#include <stdlib.h>

#define ISOSCELE 1
#define SCALENO 2
#define EQUILATERO 3

//c = a % b // a 'c' viene assegnato il resto della divisione tra 'a' e 'b'


void clearBuffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}


int leggi_intero_positivo(void){ //controlla sto void
     
     int a;
     int controllo;


    do{
        /*mettiamo controllo = scanf... perchè nel momento in cui viene inserito correttamente un numero, 
        l'operazione andata a buon fine restituisce 1, quindi controllo vale 1*/
        /*mentre invece se viene digitato un carattere sbagliato, non verrà asegnato nulla ad 'a' quindi
        controllo sarà uguale a 0 non essendo andata a buon fine l'operazione e quindi non uscirà dal loop
        del while*/
        controllo = scanf("%d", &a);
        if(controllo != 1){
            printf("Non inserito valore intero\n");
            clearBuffer();
            //il clearBuffer è importante perchè fa si che il do-while non crei un loop infinito
        } else if(a<=0){
            printf("Inserito valore negativo\n");
        }
    }while(controllo != 1 || a <= 0);
     

    return a;

} 


void leggi_lati(int *l1, int *l2, int *l3){

    printf("Inserisci la dimensione del primo lato: \n");
    // scanf("%d", l1); //senza la &  -> // problema è un processo lungo quindi fai la cosa succesiva 
    *l1 = leggi_intero_positivo();

    printf("Inserisci la dimensione del secondo lato: \n");
    *l2 = leggi_intero_positivo();

    printf("Inserisci la dimensione del terzo lato: \n");
    *l3 = leggi_intero_positivo();
}

int definisciTriangolo(int l1, int l2, int l3){
    if(l1 == l2 && l1 == l3){
        return EQUILATERO;
    } else if(l1 == l2 || l1 == l3 || l2 == l3){
        return ISOSCELE;
    }else {
        return SCALENO;
    }
}

void stampaTipoTriangolo(int tipo){
    switch(tipo){
        case EQUILATERO: printf("triangolo EQUILATERO\n");
        break;
        case ISOSCELE: printf("triangolo ISOSCELE\n");
        break;
        case SCALENO: printf("triangolo SCALENO\n");
        break;
        default: printf("ERRORE\n");
        break;
    }
}

int main(){

    int lato1, lato2, lato3; //lati
    int tipo_triangolo;

    leggi_lati(&lato1, &lato2, &lato3);  //gli passiamo gli indirizzi di memoria per poter usare la stessa funzione per tutti e 3 i lati
    printf("Lato1: %d lato2: %d lato3: %d", lato1, lato2, lato3);

    int tipoTriangolo = definisciTriangolo(lato1, lato2, lato3); // ci serve una stringa ma possiamo codificare il risultato com il define
    /*in definisciTriangolo facciamo un passaggio per valore e non per indirizzo perchè
    a noi non serve modificare il contenuto delle variabile ma servono solo in lettura*/
    
    printf("tipo triangolo: %d\n", tipoTriangolo);
    
    stampaTipoTriangolo(tipoTriangolo);



    return 0;
}