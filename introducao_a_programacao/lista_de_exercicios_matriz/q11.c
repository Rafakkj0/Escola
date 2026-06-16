// Escreva um programa que solicite ao usuário as dimensões nL  e nC de uma matriz, garantindo, por
// meio de uma estrutura de validação, que ambos os valores fornecidos para as dimensões sejam
// estritamente maiores que zero e menores que vinte (0 < nL < 20) e (0 < nC < 20) , exigindo uma
// nova digitação caso os limites não sejam respeitados. Em seguida, o programa deve ler os valores
// inteiros para preencher a matriz. Após a entrada de dados, o programa deve analisar o conteúdo da
// matriz e exibir na tela cada um dos valores distintos nela presentes, acompanhado do seu respectivo
// número total de ocorrências (frequência de aparecimento).

#include <stdio.h>

#define TAM_MAX_MATRIZ 20

int main(){
    int matriz[TAM_MAX_MATRIZ][TAM_MAX_MATRIZ];
    int repetidos[TAM_MAX_MATRIZ*TAM_MAX_MATRIZ], qtdRepetidos = 0;
    int linhas, colunas;

    while(1){
        printf("Fonceça a quantidade de linhas: ");
        scanf("%d", &linhas);
        if(linhas > 0 && linhas < TAM_MAX_MATRIZ) break;
        printf("Valor fornecido invalido, o número deve ser maior que 0 e menor que %d.\n", TAM_MAX_MATRIZ);
    }
    while(1){
        printf("Forneça a quantidade de colunas: ");
        scanf("%d", &colunas);
        if(colunas > 0 && colunas < TAM_MAX_MATRIZ) break;
        printf("Valor fornecido invalido, o número deve ser maior que 0 e menor que %d", TAM_MAX_MATRIZ);
    }
    for(int i = 0; i < linhas; i++){
        for(int k = 0; k < colunas; k++){
            printf("(%d, %d): ", i, k);
            scanf("%d", &matriz[i][k]);
        }
    }
    for(int i = 0; i < linhas; i++){
        for(int k = 0; k < colunas; k++){
            int achou = 0;
            for(int j = 0; j < qtdRepetidos; j++){
                if(matriz[i][k] == repetidos[j]){
                    achou = 1;
                }
            }
            if(achou == 0){
                repetidos[qtdRepetidos] = matriz[i][k];
                qtdRepetidos++;
                int cont = 0;
                for(int l = 0; l < linhas; l++){
                    for(int o = 0; o < colunas; o++){
                        if(matriz[i][k] == matriz[l][o]) cont++; 
                    }
                }
                printf("O número %d aparece %d vezes.\n", matriz[i][k], cont);
            }
        }
    }
    return 0;
}