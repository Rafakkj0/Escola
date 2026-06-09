// Na Teoria de Sistemas, define-se como elemento minimax de uma matriz o menor elemento da
// linha onde se encontra o maior elemento de toda a matriz. Escreva um programa que preencha uma
// matriz M de dimensões 15x15 com valores inteiros fornecidos pelo usuário. Em seguida, o
// programa deve analisar a matriz para identificar e exibir o valor do elemento minimax, indicando
// também em qual linha e coluna ele está localizado. Caso haja mais de um elemento com o maior
// valor global, adote a linha da primeira ocorrência encontrada para realizar a busca pelo menor
// elemento. 

#include <stdio.h>

#define TAM 2

int main(){
    int mat[TAM][TAM];
    int maiorValor, posMaiorValor, minimax, posMinimax;

    printf("\nForneça os valores da matriz:\n");
    for(int i=0; i<TAM; i++){
        for(int k=0; k<TAM; k++){
            printf("(linha = %d, coluna = %d)", i + 1, k + 1);
            scanf("%d", &mat[i][k]);
        }
    }

    maiorValor = mat[0][0];
    for(int i=0; i<TAM; i++){
        for(int k=0; k<TAM; k++){
            if(mat[i][k] > maiorValor){
                maiorValor = mat[i][k];
                posMaiorValor = i;
            }
        }
    }

    minimax = mat[posMaiorValor][0];
    for(int k=1; k<TAM; k++){
        if(mat[posMaiorValor][k] < minimax){
            minimax = mat[posMaiorValor][k];
            posMinimax = k;
        }
    }

    printf("O minimax é %d. Ele está localizado na linha %d e coluna %d\n", minimax, posMaiorValor + 1, posMinimax + 1);

    return 0;
}