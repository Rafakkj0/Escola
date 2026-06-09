// Faça um programa que leia uma matriz A 12x13 de inteiros e divide todos os 13 elementos de cada
// uma das 12 linhas de A pelo valor do maior elemento em módulo daquela linha. Escrever a matriz A
// lida e a matriz A modificada.

#include <stdio.h>

#define QTD_LINHAS 12
#define QTD_COLUNAS 13

int main(){
    int a[QTD_LINHAS][QTD_COLUNAS];
    float aMod[QTD_LINHAS][QTD_COLUNAS];

    for(int i=0; i<QTD_LINHAS; i++){
        printf("Forneça os valores da %dº linha:\n", i+1);
        for (int k=0; k<QTD_COLUNAS; k++){
            printf("%dº coluna: ", k+1);
            scanf("%d", &a[i][k]);
        } 
    }

    for(int i=0; i<QTD_LINHAS; i++){
        int maior = a[i][0];
        for(int k = 1; k<QTD_COLUNAS; k++){
            if(a[i][k] > maior) maior = a[i][k];
        }
        for(int k=0; k<QTD_COLUNAS; k++){
            aMod[i][k] = (float)a[i][k]/maior;
        }
    }

    printf("Matriz original:\n");
    for(int i=0; i<QTD_LINHAS; i++){
        for(int k=0; k<QTD_COLUNAS; k++){
            printf("%d\t", a[i][k]);
        }
        printf("\n");
    }

    printf("Matriz modificada:\n");
    for(int i=0; i<QTD_LINHAS; i++){
        for(int k=0; k<QTD_COLUNAS; k++){
            printf("%.2f\t", aMod[i][k]);
        }
        printf("\n");
    }
    return 0;
}