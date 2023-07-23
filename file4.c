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

struct dati_t *leggifile(FILE *f, int *dout);

void printID(struct dati_t in);

int main(int argc, char *argv[]){
    //strutture dati fondamentali
    FILE *f;
    int dim = 0;
    struct dati_t *data = NULL;
    //controllo inserimento dati
    if(argc != 2){
        fprintf(stderr, "errore inserimento dati");
        return 1;
    }
    //controllo apertura file
    f = fopen(argv[1], "r");
    if(!f){
        fprintf(stderr, "errore nell'apertura del file");
        return 2;
    }
    //esecuzione operazione/i sul file
    data = leggifile(f, &dim);

    #if 0
    printf("\n%d\n", dim);
    #endif

    //stampa id
    puts("\n[IDENTIFICATIVI]");
    for(int i = dim-1; i >= 0; i--){
        printID(data[i]);
    }

    //chiusura file e liberamento di memeoria
    fclose(f);
    free(data);

    return 0;
}

struct dati_t *leggifile(FILE *f, int *dout){
    struct dati_t *in;
    char buff[MAXVAL];
    int dim = 0;
    int actualdim = 2;
    in = malloc(sizeof(*in) * actualdim);    
    

    int chk;
    struct dati_t *c;

    while((fgets(buff, sizeof(buff), f))){
        
        if(dim >= actualdim){
            actualdim *= 2;
            in = realloc(in, sizeof(*in) * (actualdim + 1));
        }

        chk = 0;

        c = in + dim;

        chk = sscanf(buff, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", &(c->anno), &(c->mese), &(c->giorno),
        &(c->ora), &(c->min), &(c->sec), &(c->millisec), (c->ID), &(c->temp), &(c->umid), &(c->vel));

        if(chk == 11)
        dim ++;
    }

    in = realloc(in, sizeof(*in) * dim);

    *dout = dim;

    return in;
}

void printID(struct dati_t in){
    printf("%s\n", in.ID);
}