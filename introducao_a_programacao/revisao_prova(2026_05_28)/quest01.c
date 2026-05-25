// Implemente uma função que receba um vetor de números inteiros e retorne um novo vetor contendo
// apenas os elementos que aparecem exatamente uma única vez no vetor original (ou seja, elementos
// sem duplicatas).

#include <stdio.h>

#define TAM 10

int removerRepetidos(int vetor[],int tamanho, int novoVetor[]){
    int cont, posNovoVetor = 0;
    for(int i = 0; i < tamanho; i++){
        cont = 0;
        for(int k = 0; k < tamanho && cont < 2; k++){
            if(vetor[i] == vetor[k]){
                cont++;
            }
        }
        if(cont == 1){
            novoVetor[posNovoVetor] = vetor[i];
            posNovoVetor++;
        }
    }
    return posNovoVetor;
}

int main(){
    int vet[TAM], novoVet[TAM], novoTam;
    
    printf("\nEscreva os números para remover os repetidos e deixar somente os que aparecem uma única vez.\n");
    for(int i = 0; i < TAM; i++){
        printf("> ");
        if(scanf("%d", &vet[i]) == 0){
            printf("Erro, tente novamente.\n");
            while(getchar() == '\n');
            i--;
        }
    }
    
    novoTam = removerRepetidos(vet, TAM, novoVet);

    printf("\nVetor sem os números que se repetem: ");
    for(int i=0; i<novoTam; i++) printf("%d ", novoVet[i]);
    printf("\n\n");
    return 0;
}