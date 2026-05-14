// Implemente uma função que receba como parâmetros dois vetores de números inteiros e seus
// respectivos tamanhos. O objetivo da função é identificar se o primeiro vetor (denominado subvetor)
// está integralmente contido dentro do segundo vetor (vetor geral). Para que a presença seja validada,
// os elementos do subvetor devem aparecer no vetor geral exatamente na mesma sequência e de
// forma consecutiva. A função deve retornar um valor booleano ou inteiro (1 para verdadeiro e 0 para
// falso) indicando o sucesso da busca. No programa principal, o usuário deve inserir os dados de
// ambos os vetores, e o resultado da verificação deve ser exibido de forma clara na saída padrão.

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 10

int verificarPadrao(int vetOriginal[], int tamOriginal, int subVetor[], int tamSub){
    int cont;
    for(int i = 0; i <= tamOriginal - tamSub; i++){
        cont = 0;
        for(int k = 0; k < tamSub; k++){
            if(vetOriginal[i+k] == subVetor[k]){
                cont++;
            }
            else{
                break;
            }
        }
        // verificando se o padrão foi encontrado
        if(cont == tamSub) return 1;
    }
    return 0;
}

// int verificarPadrao(int vetOriginal[], int tamOriginal, int subVetor[], int tamSub){
//     int k, i;
//     for(i = 0; i <= tamOriginal - tamSub; i++){
//         for(k = 0; k < tamSub; k++){
//             if(vetOriginal[i+k] != subVetor[k]) break;
//         }
//         // verificando se o padrão foi encontrado
//         if(k == tamSub) return 1;
//     }
//     return 0;
// }

int main(){
    int v1[TAMANHO], v2[2];
    printf("\n\nForeça o vetor original:\n");
    lerVetor(v1, TAMANHO);
    printf("\nFornaça o sub vetor:\n");
    lerVetor(v2, 2);

    if(verificarPadrao(v1, TAMANHO, v2, 2) == 1) printf("\nO padrão do sub vetor foi encontrado no vetor original.\n\n");
    else printf("\nNão foi enontrado o padrão do sub vetor no vetor original.\n\n");
    return 0;
}