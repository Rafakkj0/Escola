// Um usuário digitou 12 números inteiros. Faça um programa que:
// • Leia os números
// • Armazene em um vetor
// • Conte quantos valores diferentes existem

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 12

int main(){
    int v[TAMANHO], cont=0, encontrou;

    printf("\n\nForneça %d números inteiros:\n", TAMANHO);
    lerVetor(v, TAMANHO);

    for(int i=0; i<TAMANHO; i++){
        encontrou = 0;
        for(int k=0; k < i; k++){
            if(v[i] == v[k]){
                encontrou = 1;
                break;
            }
        }
        if(encontrou == 0) cont++;
    }

    printf("\nExistem %d valores diferentes.\n\n", cont);

    return 0;
}