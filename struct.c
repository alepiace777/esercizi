/*Programma terminato sulle struct, ripassa la sscanf
USA -lm PER EVITARE ERRORI DI COMPILAZIONE CON GCC
cerca di risolvere l'errore di pvcheck*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXVAL 10

struct punto{
    double x;
    double y;        
};

struct rettangolo_t{
    struct punto p1;
    struct punto p2;
};


struct punto leggiPunto();

void stampaPunto(struct punto input);

double distanza(struct punto input1, struct punto input2);

int puntoInterno(struct rettangolo_t rect, struct punto input);

double calcoloArea(struct rettangolo_t rect);

void distMax(int *p1, int *p2, struct punto punti[MAXVAL], int n);

int main(){
    int i = 0;
    int n;
    char buffer[20];

   
    printf("inserire un numero di punti: ");
    n = atoi(fgets(buffer, sizeof(int), stdin));
    
    if(n<1){
        return 1;
    } else if(n>10){
        n = 10;
    }

    struct punto punti[MAXVAL];

    while(i<n){
        punti[i] = leggiPunto();
        i++;
    }
    
    puts("\n[PUNTI]");
    for(int idx = 0; idx<n; idx++){
        stampaPunto(punti[idx]);
    }
    struct punto origine = {0 , 0};

    puts("\n[DISTANZE]");
    double dist[MAXVAL/2];
    for(int idx = 0; idx<n; idx++){
        dist[idx] = distanza(punti[idx], origine);
        printf("%.3lf\n", dist[idx]);
    }

    //rettangolo
    //struct punto rect[2];
    
    struct rettangolo_t rect;
    rect.p1 = leggiPunto();
    rect.p2 = leggiPunto();

    //punti interni al rettangolo
    struct punto intern[MAXVAL];
    int idPi = 0;
    
    puts("\n[INTERNI]");
    for(int idx = 0; idx<n; idx++){
        int temp = puntoInterno(rect, punti[idx]);
        if(temp){
            intern[idPi] = punti[idx];
            idPi++;
        }
    }
    
    for(int idx = 0; idx<idPi; idx++){
        stampaPunto(intern[idx]);
    }

    //area rettangolo
    puts("\n[AREA]");
    double temp = 0;
    temp = calcoloArea(rect);
    printf("%.3lf\n", temp);

    //punti piu` distanti
    puts("\n[COPPIA]");
    int v1, v2;
    distMax(&v1, &v2, punti, n);

    stampaPunto(punti[v1]);
    stampaPunto(punti[v2]);

    return 0;
}




//dichiarazione funzione leggiPunto
struct punto leggiPunto(){
    char buffer[20];
    char input[20];
    struct punto nPunto = {0};
    printf("\ninserire un valore per la x ed uno per la y: ");
    strcpy(input, fgets(buffer, sizeof(buffer), stdin));
    
    //la sscanf serve per leggere una serie di dati da una stringa formattata.
    sscanf(input, "%lf %lf", &nPunto.x, &nPunto.y);

    return nPunto;
}

void stampaPunto(struct punto input){
    printf("(%.3lf, %.3lf)\n", input.x, input.y);
}

/* ricorda che la distanza tra due punti si calcola sottraendo il secondo punto dal primo e facendo
la radice dei quadrati */
double distanza(struct punto input1, struct punto input2){
    double res;
    double x = (input1.x-input2.x);
    double y = (input1.y-input2.y);
    res = sqrt(x*x + y*y);
    return res;
}

int puntoInterno(struct rettangolo_t rect, struct punto input){
    if(rect.p1.x < rect.p2.x && rect.p1.y < rect.p2.y){
        if(input.x <= rect.p2.x && input.x >= rect.p1.x){
            if(input.y <= rect.p2.y && input.y >= rect.p1.y){
                return 1;
            }
        }
    } else if(rect.p1.x > rect.p2.x && rect.p1.y > rect.p2.y){
        if(input.x <= rect.p1.x && input.x >= rect.p2.x){
            if(input.y <= rect.p1.y && input.y >= rect.p2.y){
                return 1;
            }
        }
    } else if(rect.p1.x > rect.p2.x && rect.p1.y < rect.p2.y){
        if(input.x <= rect.p1.x && input.x >= rect.p2.x){
            if(input.y <= rect.p2.y && input.y >= rect.p1.y){
                return 1;
            }
        }
    } else {
        if(input.x <= rect.p2.x && input.x >= rect.p1.x){
            if(input.y <= rect.p1.y && input.y >= rect.p2.y){
                return 1;
            }
        }
    }
    return 0;
}

double calcoloArea(struct rettangolo_t rect){
    double res = 0;
    res = ((rect.p1.x - rect.p2.x) * (rect.p1.y - rect.p2.y));
    if(res < 0){
        res = -res;
    }
    return res;
}

void distMax(int *p1, int *p2, struct punto punti[MAXVAL], int n){
    double max = distanza(punti[0], punti[1]);
    int dist = 0;
    for(int i = 0; i < (n-1); i++){
        for(int j = i+1; j<n; j++){
            dist = distanza(punti[i], punti[j]); 
            if(dist > max){
                max = dist;

                *p1 = i;
                *p2 = j;
            }
        }
    }
}