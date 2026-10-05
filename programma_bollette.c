#include <stdio.h>
#include <stdlib.h>
#define QUOTA_FISSA 12
#define TARIFFA_BASE 0.80
#define TARIFFA_ECCEDENTE 1.10
#define QUOTA_MINIMA_MQ 0
#define QUOTA_MASSIMA_MQ 5000
#define CAMBIO_VALUTA_MQ 100

#define VETTORE_BOLLETTE 12

void clearBuffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

enum sceltaMenu{
    ESCI,
    NUOVA_BOLLETTA,
    MOSTRA_BOLLETTA,
    RICHIESTA_MESE,
    CONVERSIONE,
}; //claude consiglia di non scrivere nulla dopo la virgola

int Menu_inserimento(void){ /*In C le parentesi vuote significano "parametri non specificati",
                            non "nessun parametro". Con (void) dici chiaramente che non ne ha, e il compilatore ti protegge 
                            se per sbaglio ne passi uno.*/
    int controllo;
    int scelta_menu;

    do{
        printf("\n");
        printf("*******MENU*******\n");
        printf("PREMI: \n");
        printf("1) per inserire una nuova bolletta\n");
        printf("2) per mostrare l'ultima bolletta inserita\n");
        printf("3) per sapere la bolletta del mese corrispondente alla richiesta\n");
        printf("4) per convertire il risultato da euro a dollari\n");
        printf("0) per uscire\n");
        printf("*************************\n");
        printf("\n");

        controllo = scanf("%d", &scelta_menu);

        if(controllo != 1){
            printf("Inserisci un valore numerico\n");
            clearBuffer();
        }else if(scelta_menu < 0 || scelta_menu > 4){
            printf("Stai inserendo un valore non compreso tra 0 e 4, ritente: \n");
            clearBuffer();
        }
    }while(controllo != 1 || scelta_menu < 0 || scelta_menu > 4);
    

    return scelta_menu;

}

int inserisci_bolletta(){

    int metri_cubi;
    int controllo; 
    printf("Hai premuto 1) per l'inserimento di una nuova bolletta\n");  
    
    do{
        printf("Inserire i m^3: \n");
        controllo = scanf("%d", &metri_cubi);
        if(controllo != 1){
            printf("ERRORE, inserire un valore numerico\n");
            clearBuffer();
        }else if(metri_cubi < QUOTA_MINIMA_MQ || metri_cubi > QUOTA_MASSIMA_MQ){
            printf("Inserisi un valore compreso tra %d e %d", QUOTA_MINIMA_MQ, QUOTA_MASSIMA_MQ);
            clearBuffer();
        }
    }while(controllo != 1 || metri_cubi < QUOTA_MINIMA_MQ || metri_cubi > QUOTA_MASSIMA_MQ);

    return metri_cubi;
}

int calcola_bolletta(int *metriCubi){

    double bolletta_calcolo;

    printf("Prezzo di partenza base 12 euro\n");
    if(*metriCubi < CAMBIO_VALUTA_MQ){
        printf("Nel caso in cui i metri cubi sono minori di %d si attiva la tariffa di: ", CAMBIO_VALUTA_MQ);
        printf("% 2.2f al metro cubo\n", TARIFFA_BASE);
        bolletta_calcolo = QUOTA_FISSA + (*metriCubi * TARIFFA_BASE);
    }else if(*metriCubi > CAMBIO_VALUTA_MQ){
        printf("Nel caso in cui i metri cubi sono maggiori di %d si attiva la tariffa di: ",CAMBIO_VALUTA_MQ);
        printf("% 2.2f al metro cubo\n", TARIFFA_ECCEDENTE);
        bolletta_calcolo = QUOTA_FISSA + (*metriCubi * TARIFFA_ECCEDENTE);
    }

    return bolletta_calcolo;
    
}

void mostra_bollette(int VET[]){

    for(int i = 0; i < 12; i++){
        printf("MESE %d: -> %d\n",i, VET[i]);
    }

    /*Scrivere int v[] o int *v nei parametri è la stessa cosa: sono due notazioni per lo stesso tipo,
    motivo per cui quando andiamo a lavorare sui vettori non dobbiamo utilizzare &*opp &.*/
}

void lettura_del_mese(int VET[]){  //ricorda che nella chiamata alla funzione passi una copia del parametro

    int scelta_mese;
    int controllo;

    #define min_mese 0
    #define max_mese 11

    printf("Inserisci il mese di cui vuoi verificare la bolletta: (da 0 a 11)\n");
    do{
        
        controllo = scanf("%d", &scelta_mese);
        if(controllo != 1){
            printf("ERRORE, inserisci un valore numerico\n");
            clearBuffer();
        }else if(scelta_mese < min_mese || scelta_mese > max_mese){
            printf("ERRORE, inserisci un numero compreso tra 0 e 11\n");
            clearBuffer();
        }


    }while(controllo != 1 || scelta_mese < min_mese || scelta_mese > max_mese);


    printf("MESE %d: %d\n", scelta_mese, VET[scelta_mese]);

}


int main(void){

        int contatore = 0;
        double ultima_bolletta;
        int scelta;
        int metri_cubi;
        int vettore[VETTORE_BOLLETTE];

        for(int i = 0; i < 12; i++){
            vettore[i] = 0;
        }

        do{
            //enum sceltaMenu numero_scelto;  
            /*non serve dichiararlo nel main, l'enum crea delle costanti e non delle
                                            variabili, quindi non è necessario creare altre variabili a cui assegnare un 
                                            valore avento già scelta*/
            scelta = Menu_inserimento(); //attenzione a mettere scelta = altrimenti non viene salvato nessun valore
            /*scelta_selta è un passaggio per valore quindi stiamo lavorando su una copia, motivo per cui bisogna fare
            questo passagio di scelta = così li assegniamo effettivamente il valore inserito*/
            
            //scanf("%d", &numero_scelto);
            switch(scelta){
                case NUOVA_BOLLETTA: 
                    metri_cubi = inserisci_bolletta();
                    ultima_bolletta = calcola_bolletta(&metri_cubi);
                    printf("Il calcolo totale della bolletta è di: % 2.2f euro\n", ultima_bolletta);
                    printf("-------------------------\n");
                    vettore[contatore] = ultima_bolletta;
                    contatore++;
                    printf("Numero bollette inserite: %d\n", contatore);
                    printf("-------------------------\n");
                break;
                case MOSTRA_BOLLETTA:
                    mostra_bollette(vettore);
                break;
                case RICHIESTA_MESE: 
                    lettura_del_mese(vettore);
                break;
                case CONVERSIONE:

                break;
                case ESCI:
                    printf("Grazie per aver usufruito il nostro servizio\n");
                    return 0;
                break;
            }
        }while(scelta != ESCI);
    return 0;
}
