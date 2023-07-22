#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1024
#define MAXLEN 7

struct dati_t{
    int anno, mese, giorno;
    int ora, min, sec, millisec;
    char ID[10];
    float temp;
    int umid;
    float vel;
};

void caricaDati(FILE *f, struct dati_t *in);

void stampaDati(struct dati_t pr);

void checkNoct(struct dati_t in);

int checkMaxTemp(struct dati_t in[MAXLEN], int n);

int main(int argc, char *argv[]){
    FILE *f;

    if(argc != 2){
	    printf("Numero di parametri errato\n");
	    return 1;
    }

    f = fopen(argv[1], "r");
    
    if(f == NULL){
        printf("Errore apertura file\n");
        return 1;
    }

    struct dati_t data[MAXLEN];


    caricaDati(f, data);



    fclose(f);
    free(f);

    return 0;
}

void caricaDati(FILE *f, struct dati_t *data){

    char buff[MAXVAL] = {0};
    int i = 0;

    while(i < MAXLEN){        
        sscanf(buff,"%d-%d-%d %d:%d:%d.%d %s %f %d%% %f", &data[i].anno, &data[i].mese, &data[i].giorno, &data[i].ora, &data[i].min,
        &data[i].sec, &data[i].millisec, data[i].ID, &data[i].temp, &data[i].umid, &data[i].vel);
        i ++;
    }

    #if 1
    for(int idx = 0; idx<i; idx++){
        puts("\nstampa elemento");
        stampaDati(data[idx]);
    }    
    #endif

    

    puts("\n[MAX-TEMP]");
    int val;
    val = checkMaxTemp(data, i);
    printf("%.1f\n", data[val].temp);

    puts("\n[RIGHE]");
    printf("%d", i);
}

void stampaDati(struct dati_t pr){
    printf("%d-%d-%d %d:%d:%d.%d %s %.1f %d%% %.1f\n", pr.anno, pr.mese, pr.giorno,
    pr.ora, pr.min, pr.sec, pr.millisec, pr.ID, pr.temp, pr.umid, pr.vel);
}

void checkNoct(struct dati_t in){
    if(in.ora < 6 || in.ora >= 22){
        stampaDati(in);
    }
}


int checkMaxTemp(struct dati_t in[MAXLEN], int n){
    //assumendo che i gradi siano celsius
    int maxTemp = -274;
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(in[i].temp > maxTemp){
            maxTemp = in[i].temp;
            idx = i;
        }
    }
    return idx;
}