/* ad un puntatore devi passare l'INDIRIZZO DELLA VARIABILE,
a meno che non passi un vettore di dati*/
#include <stdio.h>
#include <stdlib.h>

struct dati_t{
    int anno, mese, giorno;
    int ora, min, sec, millisec;
    char ID[10];
    float temp;
    int umid;
    float vel;
};

struct dati_t *leggiFile(FILE *f, int *dout);

void stampaID(struct dati_t in);

float maxTemp(struct dati_t *in, int dim);


int main(int argc, char *argv[]){

    struct dati_t *data;
    FILE *f;
    int dim;

    if(argc != 2){
        fprintf(stderr, "\nerrore inserimento dati\n");
        return 1;
    }

    f = fopen(argv[1], "r");    

    if(!f){
        fprintf(stderr, "\nerrore apertura file\n");
        return 2;
    }

    data = leggiFile(f, &dim);


    puts("\n[IDENTIFICATIVI]");
    for(int i = (dim - 1); i >= 0; i--){
        stampaID(data[i]);
    }

    puts("\n[MAX-TEMP]");
    float tempVal;
    tempVal = maxTemp(data, dim);
    printf("%.1f\n", tempVal);


    puts("\n[RIGHE]");
    printf("%d", dim);

    fclose(f);
    free(data);

    return 0;
}

struct dati_t *leggiFile(FILE *f, int *dout){
    
    struct dati_t *in;
    char buff[1000];
    int min = 0;
    int max = 0;

    min = atoi(fgets(buff, sizeof(buff), f));
    max = atoi(fgets(buff, sizeof(buff), f));

    in = malloc(sizeof(struct dati_t) * (max - min));

    int i = min;
    int dim = 0;
    
    if(i > 0){
        int idx = 0;
        while(idx < i){
            fgets(buff, sizeof(buff), f);
            idx ++;
        }
    }

    while((fgets(buff, sizeof(buff), f)) && i < max){
        in[dim].giorno = 0;
        sscanf(buff, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", &in[dim].anno, &in[dim].mese, &in[dim].giorno, &in[dim].ora,
        &in[dim].min, &in[dim].sec,  &in[dim].millisec, in[dim].ID, &in[dim].temp, &in[dim].umid, &in[dim].vel);

        if(in[dim].giorno != 0)
        dim ++;
        i ++;
    }

    *dout = dim;

    return in;
}

void stampaID(struct dati_t in){
    printf("%s\n", in.ID);
}

float maxTemp(struct dati_t *in, int dim){
    float tempMax = -273.15;
    for(int i = 0; i < dim; i++){
        if(in[i].temp > tempMax){
            tempMax = in[i].temp;
        }
    }
    return tempMax;
}