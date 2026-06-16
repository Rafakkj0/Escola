// Faça um programa que receba:
// a) 10 nomes de produtos e armazene-os em um vetor (o nome é único);
// b) O estoque de cada um destes produtos, em cada um dos 5 armazéns e armazene-os em uma
// matriz 5X10;
// c) O custo(preço) dos 10 produtos e armazene-os em um vetor.
// Deve ser calculado e impresso:
// • O total de itens armazenados em cada armazém;
// • O total de itens armazenados de cada produto em todos os armazéns juntos;
// • O nome e o valor estocado de cada produto(soma dos armazéns)

#include <stdio.h>
#include <string.h>

#define QTD_PRODUTOS 2
#define QTD_ARMAZENS 3
#define TAM_MAX_NOME 100

void limpaBuffer(){
    while(getchar() != '\n'){}
}

int main(){
    char produto[QTD_PRODUTOS][TAM_MAX_NOME];
    float estoque[QTD_PRODUTOS][QTD_ARMAZENS];
    float preco[QTD_PRODUTOS];

    for(int i = 0; i < QTD_PRODUTOS; i++){
        while(1){
            printf("\nForneça o nome do produto: ");
            fgets(produto[i], TAM_MAX_NOME, stdin);
            int tam = strlen(produto[i]);
            if(tam == TAM_MAX_NOME - 1){
                if(produto[i][TAM_MAX_NOME-1] == '\n'){
                    produto[i][TAM_MAX_NOME-1] = '\0';
                }
                else{
                    limpaBuffer();
                }
            }
            else{
                produto[i][tam-1] = '\0';
            }
            int achou = 0;
            for(int k = 0; k < i && achou == 0; k++){
                if(strcmp(produto[i], produto[k]) == 0) achou = 1;
            }
            if(achou == 0) break;
            else printf("Nome repetido, tente novamente.\n");
        }

        for(int k = 0; k < QTD_ARMAZENS; k++){
            while(1){
                printf("Forneça o estoque do armazén %d:", k+1);
                scanf("%f", &estoque[i][k]);
                limpaBuffer();
                if(estoque[i][k] >= 0) break;
                printf("Valor invalido.\n");
            }
        }

        while(1){
            printf("Forneça o preço: ");
            scanf("%f", &preco[i]);
            limpaBuffer();
            if(preco[i] > 0) break;
            printf("Valor invalido.\n");
        }
    }

    printf("\n\n");

    for(int i = 0; i < QTD_PRODUTOS; i++){
        float qtdTotal = 0;

        printf("- - %s:\n", produto[i]);
        printf("- Quantidade em cada armazén:\n");
        for(int k = 0; k <QTD_ARMAZENS; k++){
            printf("Armazén %d: %.2f\n", k+1, estoque[i][k]);
            qtdTotal += estoque[i][k];
        }
        printf("- Soma dos armazéns: %f\n", qtdTotal);
        printf("- Valor estocado: R$ %.2f\n\n", qtdTotal * preco[i]);
    }
    return 0;
}