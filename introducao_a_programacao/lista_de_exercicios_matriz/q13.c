// Uma empresa que possui 20 funcionários, guarda a quantidade vendida por cada um de seus
// funcionários em cada um dos 7 dias dasemana. Faça um programa que:
// • Mostre a quantidade vendida por cada funcionário;
// • Mostre em qual ou quais dias da semana cada funcionário vendeu mais;
// • O nome do funcionário ou funcionários com maior valor de venda na semana;
// • Para cada dia da semana, a quantidade vendida por cada funcionário.

#include <stdio.h>
#include <string.h>

#define NUM_DIAS_SEMANA 7
#define NUM_FUNCIONARIOS 2
#define MAX_TAM_NOME 100

void limpaBuffer(){
    while(getchar() != '\n');
}

int main(){
    float vendas[NUM_FUNCIONARIOS][NUM_DIAS_SEMANA];
    char nome[NUM_FUNCIONARIOS][MAX_TAM_NOME];
    char diasSemana[NUM_DIAS_SEMANA][20] = {
        "Domingo",
        "Segunda",
        "Terça",
        "Quarta",
        "Quinta",
        "Sexta",
        "Sabado"
    };

    for(int i = 0; i < NUM_FUNCIONARIOS; i++){
        printf("Forneça o nome do %dº funcionario: ", i+1);
        fgets(nome[i], MAX_TAM_NOME, stdin);
        int tam = strlen(nome[i]);
        if(nome[i][tam-1] == '\n') nome[i][tam-1] = '\0';
        else limpaBuffer();
        // Lendo a quantidade de vendas em cada dia da semana pelo funcionario:
        printf("Quantidade de vendas feitas pelo funcionario:\n");
        for(int d = 0; d < NUM_DIAS_SEMANA; d++){
            printf("%s: ", diasSemana[d]);
            scanf("%f", &vendas[i][d]);
        }
        limpaBuffer();
    }

    printf("\n==================================\n");

    printf("\nQuantidade vendida por cada funcionario:\n");
    for(int i = 0; i < NUM_FUNCIONARIOS; i++){
        int soma = 0;
        for(int k = 0; k < NUM_DIAS_SEMANA; k++) soma += vendas[i][k];
        printf("%s: %d\n", nome[i], soma);
    }

    printf("\nDias em que cada funconario vendeu mais:\n");
    for(int i=0; i < NUM_FUNCIONARIOS; i++){
        int maior = vendas[i][0];
        for(int k = 1; k < NUM_DIAS_SEMANA; k++){
            if(vendas[i][k] > maior) maior = vendas[i][k];
        }
        printf("%s: ", nome[i]);
        int qtd=0;
        for(int k = 0; k < NUM_DIAS_SEMANA; k++){
            if(vendas[i][k] == maior){
                if(qtd == 0) printf("%s", diasSemana[k]);
                else printf(", %s", diasSemana[k]);
                qtd++;
            }
        }
        printf("\n");
    }

    printf("\nQuantidade vendida por cada funcionario em cada dia da semana:\n");
    for(int k = 0; k < NUM_DIAS_SEMANA; k++){
        printf("%s:\n", diasSemana[k]);
        for(int i = 0; i < NUM_FUNCIONARIOS; i++){
            printf("  %s: %.2f\n", nome[i],vendas[i][k]);
        }
    }

    printf("\nFuncionario(s) que mais venderam em cada dia da semana:\n");
    for(int k = 0; k < NUM_DIAS_SEMANA; k++){
        printf("%s: ", diasSemana[k]);
        int maior = 0;
        for(int i = 0; i < NUM_FUNCIONARIOS; i++){
            if(vendas[i][k] > maior) maior = vendas[i][k];
        }
        int qtd=0;
        for(int i = 0; i < NUM_FUNCIONARIOS; i++){
            if(vendas[i][k] == maior){
                if(qtd == 0) printf("%s", nome[i]);
                else printf(", %s", nome[i]);
                qtd++;
            }
        }
        printf("\n");
    }

    return 0;
}