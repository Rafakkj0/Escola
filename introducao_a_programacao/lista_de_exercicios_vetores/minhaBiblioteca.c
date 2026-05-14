#include <stdio.h>
#include "minhaBiblioteca.h"

void lerVetor(int vetor[], int tamanho){
    for(int i=0; i < tamanho; i++){
        printf("> ");
        scanf("%d", &vetor[i]);
    }
}

void lerVetorCont(int vetor[], int tamanho){
    for(int i=0; i < tamanho; i++){
        printf("%dº > ", i+1);
        scanf("%d", &vetor[i]);
    }
}

void multiplicaVetores(int vetor1[], int vetor2[],int tamanho,int vetorResposta[]){
    for(int i=0; i < tamanho; i++){
        vetorResposta[i] = vetor1[i] * vetor2[1];
    }
}

float mediaVetor(int vetor[], int tamanho){
    int soma = 0;
    for(int i=0; i < tamanho; i++){
        soma += vetor[i];
    }
    return (float)soma/tamanho;
}

int modaVetor(int vetor[], int tamanho){
    int moda, cont, contM = 0;
    for(int i=0; i < tamanho; i++){
        cont = 0;
        for(int k=0; k < tamanho; k++){
            if(vetor[i] == vetor[k]){
                cont++;
            }
        }
        if(contM < cont){
            contM = cont;
            moda = vetor[i];
        }
    }
    return moda;
}