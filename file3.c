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

void leggiFile(FILE *f, struct dati_t *in);

int main(int argc, char *argv[]){

    struct dati_t *data;
    FILE *f;

    if(argc != 2){
        fprintf(stderr, "\nerrore inserimento dati\n");
        return 1;
    }

    f = fopen(argv[1], "r");    

    if(!f){
        fprintf(stderr, "\nerrore apertura file\n");
        return 2;
    }


    leggiFile(f, data);

    fclose(f);
    free(data);

    return 0;
}

void leggiFile(FILE *f, struct dati_t *in){
    char buff[1000];
    int min = 0;
    int max = 0;

    min = atoi(fgets(buff, sizeof(buff), f));
    max = atoi(fgets(buff, sizeof(buff), f));

    int i = 0;
    int dim = 0;

    while((fgets(buff, sizeof(buff), f)) && i < max){
        in[dim].giorno = 0;
        sscanf(buff, "%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", &in[dim].anno, &in[dim].mese, &in[dim].giorno, &in[dim].ora,
        &in[dim].min, &in[dim].millisec, in[dim].ID, &in[dim].temp, &in[dim].umid, &in[dim].vel);

        
    }
}