/*
* programma che vede l'implementazione di una matrice e la gestione di questa
* ricorda la logica usata per la rotazione della matrice che `e piuttosto complessa
*/

#include <stdio.h>
#include <stdlib.h>

#define NRIG 4
#define NCOL 4
#define MAXVAL 5
#define MINVAL -5

//definizione funzione stampa matrice
void stampaMatrice(int matrixx[NRIG][NCOL]);

//funzione di calcolo media per ogni riga
double mediaRiga(int matrixm[NRIG][NCOL], int row);

//funzione di calcolo media per ogni colonna
double mediaCol(int matrixm[NRIG][NCOL], int col);

//funzione di calcolo media totale
double media(int matrixm[NRIG][NCOL]);

//funzione di calcolo della frequenza dei valori
int freq(int matrixf[NRIG][NCOL], int val);

//funzione di rotazione matrice
void rotateMat(int output[NRIG][NCOL], const int input[NRIG][NCOL]);

int main(){       
    //variabili principali 
    int ins;
    char buffer[20];
    int matrix[NRIG][NCOL];
    int i = 0;

    do{
        int j = 0;
        do{        
            do{ //ciclo di richiesta dati + controllo
                printf("Inserire un valore: ");
                ins = atoi(fgets(buffer, sizeof(int), stdin));
            } while(ins>MAXVAL || ins<MINVAL);
            matrix[i][j] = ins;            
            j ++;
        } while(j<NCOL);
        i ++;
    } while(i<NRIG);

    //chiamata a funzione stampa matrice
    printf("[MATRICE]\n");
    stampaMatrice(matrix);

    //media riga
    printf("\n[MEDIA RIGHE]\n");

    for(int idx = 0; idx<NRIG; idx++){
        double temp;
        temp = mediaRiga(matrix, idx);
        printf("%1.3lf\n", temp);
    }

    //media colonna
    printf("\n[MEDIA COLONNE]\n");

    for(int idx = 0; idx<NCOL; idx++){
        double temp;
        temp = mediaCol(matrix, idx);
        printf("%1.3lf\n", temp);
    }

    //media totale
    printf("\n[MEDIA]\n");
    double temp = media(matrix);
    printf("%1.3lf\n", temp);

    //frequenza valori
    printf("\n[FREQUENZE]\n");
    for(int idx = -5; idx<=5; idx++){
        int tmp = 0;
        tmp = freq(matrix, idx);
        printf("%d\n", tmp);
    }

    //rotazione matrice
    int rotated[NRIG][NCOL];

    rotateMat(rotated, matrix);
    printf("\n[RUOTA]\n");
    stampaMatrice(rotated);

    return 0;
}

//inizializzazione funzione stampaMatrice()
void stampaMatrice(int matrixx[NRIG][NCOL]){ 
    for(int idx = 0; idx<NRIG; idx++){
        for(int n = 0; n<NCOL; n++){
            printf("%d ", matrixx[idx][n]);
        }
        printf("\n");
    }
}

//inizializzazione funzione mediaRiga()
double mediaRiga(int matrixm[NRIG][NCOL], int row){
    double total = 0;
    for(int i = 0; i<NCOL; i++){
        total += matrixm[row][i];
    }
    total /= NCOL;
    return total;    
}

//inizializzazione funzione mediaCol()
double mediaCol(int matrixm[NRIG][NCOL], int col){
    double total = 0;
    for(int i = 0; i<NRIG; i++){
        total += matrixm[i][col];
    }
    total /= NRIG;
    return total;
}

//inizializzazione funzione media()
double media(int matrixm[NRIG][NCOL]){
    double res = 0;
    for(int i = 0; i<NRIG; i++){
        for(int j = 0; j<NCOL; j++){
            res += matrixm[i][j];
        }
    }
    res /= (NRIG*NCOL);
    return res;
}

//inizializzazione funzione freq()
int freq(int matrixf[NRIG][NCOL], int val){
    int count = 0;

    for(int i=0; i<NRIG; i++){
        for(int j = 0; j<NCOL; j++){
            if(matrixf[i][j]==val)
            count++;
        }
    }
    return count;
}

//inizializzazione funzione rotateMat()
void rotateMat(int output[NRIG][NCOL], const int input[NRIG][NCOL]){
    for(int i = 0; i<NRIG; i++){
        int var = NRIG-1;
        for(int j = 0; j<NCOL; j++){
            output[i][j] = input[var][i];
            var--;
        }
    }
} 