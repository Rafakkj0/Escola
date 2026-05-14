// Um professor deseja verificar se uma sequência de números digitada pelos alunos já está em ordem
// crescente. Faça um programa que:
// • Leia 10 números inteiros
// • Armazene os números em um vetor
// • Verifique se os valores estão em ordem crescente
// • Mostre uma mensagem informando se o vetor está ou não ordenado
#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int v[TAMANHO], crescente = 1;

    printf("\n\nFornaça %d números para verificar se está em ordem crescente: \n", TAMANHO);
    lerVetor(v, TAMANHO);

    for(int i=1; i < TAMANHO && crescente == 1; i++){
        if(v[i] < v[i-1]) crescente = 0;
    }

    if(crescente == 1) printf("\nOs números estão em ordem crescente!\n\n");
    else printf("\nOs números não estão em ordem crescente!\n\n");
    return 0;
}