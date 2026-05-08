// Leia 10 números e mostre-os na ordem inversa

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int main(){
    int v[TAMANHO];

    printf("\nFornaça os números para inverter a ordem:\n");
    lerVetor(v, TAMANHO);

    printf("\nOrdem inversa:\n");
    for(int i=TAMANHO-1; i>=0; i--){
        printf("%d\n", v[i]);
    }
}