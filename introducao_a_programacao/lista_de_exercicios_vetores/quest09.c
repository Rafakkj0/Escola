// Um sistema registrou 15 números inteiros. Faça um programa que:
// • Leia os números
// • Armazene em um vetor
// • Leia um número específico
// • Conte quantas vezes esse número aparece no vetor
#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 15

int main(){
    int v[TAMANHO], n, cont = 0;

    printf("\n\nForneça os %d números que ficaram registrados: \n", TAMANHO);
    lerVetor(v, TAMANHO);

    printf("\nForneça qual número deseja verificar se está presente na lista: ");
    scanf("%d", &n);

    for(int i=0; i < TAMANHO; i++){
        if(n == v[i]) cont++;
    }

    printf("\nEste número aparece %d vezes.\n\n", cont);
    return 0;
}