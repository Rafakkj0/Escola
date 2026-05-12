// Uma fila de pessoas é representada por números. Faça um programa que:
// • Leia 10 números
// • Armazene em um vetor
// • Rotacione os valores uma posição para a direita
// Exemplo:
// Antes:
// 12345
// Depois:
// 51234

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int vFila[TAMANHO];

    printf("\n\nForneça os números das pessoas presentes na fila:\n");
    lerVetorCont(vFila, TAMANHO);
    
    int ultimo = vFila[TAMANHO - 1];

    for(int i = TAMANHO - 1; i > 0; i--){
        vFila[i] = vFila[i - 1];
    }

    vFila[0] = ultimo;

    printf("\nResultado da fila rotacionada: \n");
    printf("%d", vFila[0]);
    for(int i = 1; i < TAMANHO; i++){
        printf(" - %d", vFila[i]);
    }
    printf("\n\n");
    return 0;
}