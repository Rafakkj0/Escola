// Escreva um programa que leia valores inteiros para preencher uma matriz M de dimensões 10x20.
// Após a leitura de todos os dados, o programa deve processar a matriz e exibir na tela:
// 1. o maior elemento pertencente a cada uma das linhas;
// 2. a média aritmética dos elementos de cada uma das colunas;
// 3. o resultado do produto (multiplicação) de todos os elementos da matriz que sejam diferentes
// de zero;
// 4. a posição exata (linha e coluna) de todas as ocorrências de um valor específico, o qual deve
// ser digitado pelo usuário ao final do programa.

#include <stdio.h>

#define LINHAS 1
#define COLUNAS 2

int main(){
    int m[LINHAS][COLUNAS];
    int produto = 1, entrada;

    for(int i = 0; i < LINHAS; i++){
        for(int k = 0; k < COLUNAS; k++){
            printf("Linha %d, Coluna %d: ", i+1, k+1);
            scanf("%d", &m[i][k]);
        }
    }

    printf("\n===== Resultados =====\n");

    for(int i = 0; i < LINHAS; i++){
        int maior = m[i][0];
        for(int k = 1; k < COLUNAS; k++){
            if(m[i][k] > maior) maior = m[i][k];
        }
        printf("Maior valor da linha %d: %d\n", i+1, maior);
    }

    for(int k = 0; k < COLUNAS; k++){
        int soma = 0;
        for(int i = 0; i < LINHAS; i++) soma += m[i][k];
        printf("Média aritmédica da coluna %d: %f\n", k+1, (float) soma / LINHAS);
    }

    for(int i = 0; i < LINHAS; i++){
        for(int k = 0; k < COLUNAS; k++){
            if(m[i][k] != 0){
                produto *= m[i][k];
            }
        }
    }
    printf("Produto de todos os valores diferentes de 0: %d\n", produto);

    printf("\nQual valor deseja procurar na matriz?\n");
    scanf("%d", &entrada);
    printf("Posisões onde esse valor foi encontrado:\n");
    int achou = 0;
    for(int i = 0; i < LINHAS; i++){
        for(int k = 0; k < COLUNAS; k++){
            if(m[i][k] == entrada){
                printf("Linha %d, Coluna %d\n", i+1, k+1);
                achou = 1;
            }   
        }
    }
    if(achou == 0) printf("Valor não encontrado na matiz.\n");

    return 0;
}