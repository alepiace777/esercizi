#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000

//struttura dati complessa
struct dati_t{
    int anno, mese, giorno;
    int ora, min, sec, millisec;
    char ID[10];
    float temp;
    int umid;
    float vel;
};

struct dati_t *leggifile(struct dati_t *in, int *dim);

int main(int argc, char *argv[]){
    //strutture dati fondamentali
    FILE *f;
    int dim = 0;
    struct dati_t *data;
    //controllo inserimento dati
    if(argc != 2){
        fprintf(stderr, "errore inserimento dati");
        return 1;
    }
    //controllo apertura file
    f = fopen(argv[1], 'r');
    if(!f){
        fprintf(stderr, "errore nell'apertura del file");
        return 2;
    }
    //esecuzione operazione/i sul file


    //ecc

    //chiusura file e liberamento di memeoria
    fclose(f);
    free(f);

    return 0;
}

struct dati_t *leggifile(struct dati_t *in, int *dim){
    
}