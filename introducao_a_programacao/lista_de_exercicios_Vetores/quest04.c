// Leia 20 números e diga se algum deles se repete

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 20

int main(){
    int repete=0, v[TAMANHO];

    printf("\n\nEscreva %d números para verificar se há números repetidos.\n", TAMANHO);
    lerVetor(v, TAMANHO);

    for(int i=0; i < TAMANHO && repete == 0; i++){
        for(int k=i+1; k < TAMANHO && repete == 0; k++){
            if(v[i] == v[k]) repete = 1;
        }
    }

    if( repete == 1 ) printf("\nHá números repetidos!\n\n");
    else printf("\nNão há números repetidos.\n\n");
    
    return 0;
}