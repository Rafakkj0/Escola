#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "mystring.h"

#define QTD_MAX_PRODUTOS 100
#define MAX_CARACTERES 50


int apresentarMenu(){
    int input;

    printf("\n");
    printf("------------------ Escolha uma opção ------------------\n");
    printf("1 - Cadastrar produto         2 - Registrar venda      \n");
    printf("3 - Consultar produto         4 - Listar produtos      \n");
    printf("5 - Relatório de estoque      6 - Relatório de vendas  \n");
    printf("                     0 - Sair                          \n");
    do{
        printf("> ");
    }while(lerInt(&input) == 0 || input > 6 || input < 0);
    return input;
}

void cadastrar(char rNome[][MAX_CARACTERES], float rEstoque[], int *qtdProdutos){
    char nome[MAX_CARACTERES];
    int i;

    while(1){
        printf("\nNome do produto: ");
        if(lerString(nome, MAX_CARACTERES) == 1) break;
    }

    converteMaiuscula(nome);

    for(i = 0; i < *qtdProdutos; i++){
        if(strcmp(nome, rNome[i]) == 0){
            printf("\nEste produto já está cadastrado.\n");
            return;
        }
    }

    strcpy(rNome[i], nome);

    while(1){
        printf("\nQuantidade em estoque: ");
        if(lerFloat(&rEstoque[i]) == 0){
            printf("\nResposta invalida, insira um número.\n");
            continue;
        }
        if(rEstoque[i] <= 0){
            printf("\nQuantidade invalida, tente novamente.\n");
            continue;
        }
        break;
    }

    (*qtdProdutos)++;

    printf("\nProduto cadastrado com sucesso!\n%s\t| Estoque: %.2f\n", rNome[i], rEstoque[i]);
}

int main(){
    char rNome[QTD_MAX_PRODUTOS][MAX_CARACTERES]; // Nome dos produtos registrados
    float rEstoque[QTD_MAX_PRODUTOS]; // Quantidade em estoque dos produtos registrados.
    float rVendas[QTD_MAX_PRODUTOS]; // Quantidade vendido dos produtos registrados.
    int qtdProdutos = 0; // Quantidade de produtos cadastrados.
    int input;
    while(1){
        input = apresentarMenu();
        switch(input){
        case 1:
            cadastrar(rNome, rEstoque, &qtdProdutos);
            break;
        default:
            break;
        }
        if(input == 0) break;
    }
    return 0;
}