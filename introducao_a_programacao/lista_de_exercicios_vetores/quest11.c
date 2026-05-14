// Um sistema registrou 10 números. Faça um programa que:
// • Leia os 10 números
// • Armazene em um vetor
// • Leia um valor a ser removido
// • Remova o valor do vetor, caso exista.
// • Desloque os elementos restantes

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int v[TAMANHO], r, novoTamanho = TAMANHO;

    printf("\n\nFoneça a lista de %d números: \n", TAMANHO);
    lerVetor(v, TAMANHO);

    printf("\nQual número deseja remover da lista?\n> ");
    scanf("%d", &r);

    for(int i = 0; i < novoTamanho; i++){
        if( v[i] == r ){
            for(int k = i; k < novoTamanho - 1; k++){
                v[k] = v[k+1];
            }
            novoTamanho--;
            i--;
        }
    }

    if(novoTamanho > 0){
        printf("\nLista atualizada com os valores removidos:\n");
        printf("%d",v[0]);
        for(int i = 1; i < novoTamanho; i++){
            printf(" - %d", v[i]);
        }
    }
    else printf("\nTodos os números foram removidos.\n");

    return 0;
}