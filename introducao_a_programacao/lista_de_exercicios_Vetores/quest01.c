// Faça um programa que leia dois vetores de 10 posições e faça a multiplicação dos elementos de
// mesmo índice, colocando o resultado em um terceiro vetor. Imprimir o vetor resultante.

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int vx[TAMANHO], vy[TAMANHO], vz[TAMANHO];

    printf("\n\nForneça os %d valores do primeiro vetor:\n", TAMANHO);
    lerVetor(vx, TAMANHO);

    printf("\nForneça os %d valores do segundo vetor:\n", TAMANHO);
    lerVetor(vy, TAMANHO);

    multiplicaVetores(vx, vy, TAMANHO, vz);

    printf("\nResultado da multiplicação:\n");
    printf("%-12s %-12s %-12s\n", "Vetor 1", "Vetor 2", "Resultado");

    for(int i = 0; i < TAMANHO; i++){
        printf("%-12d %-12d %-12d\n", vx[i], vy[i], vz[i]);
    }
    return 0;
}