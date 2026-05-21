#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "mystring.h"

#define QTD_MAX_PRODUTOS 100
#define MAX_CARACTERES 25


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
    printf("-------------------------------------------------------\n");
    return input;
}

int buscarProduto(char nome[], char bNome[][MAX_CARACTERES], int *qtdProdutos){
    int i;
    for(i = 0; i < *qtdProdutos; i++){
        if(strcmp(nome, bNome[i]) == 0) return i;
    }
    return -1;
}

void cadastrar(char rNome[][MAX_CARACTERES], float rEstoque[], int *qtdProdutos){
    char nome[MAX_CARACTERES];
    int posicao;
    while(1){
        printf("\nNome do produto: ");
        if(lerString(nome, MAX_CARACTERES) == 1) break;
    }

    converteMaiuscula(nome);

    if((buscarProduto(nome, rNome, qtdProdutos)) != -1){
        printf("\nEste produto já está cadastrado.\n");
        return;
    }
    
    posicao = *qtdProdutos;

    strcpy(rNome[posicao], nome);

    while(1){
        printf("\nQuantidade em estoque: ");
        if(lerFloat(&rEstoque[posicao]) == 0){
            printf("\nResposta invalida, insira um número.\n");
            continue;
        }
        if(rEstoque[posicao] <= 0){
            printf("\nQuantidade invalida, tente novamente.\n");
            continue;
        }
        break;
    }

    (*qtdProdutos)++;

    printf("\nProduto cadastrado com sucesso!\n%s\t| Estoque: %.2f\n", rNome[posicao], rEstoque[posicao]);
}

void registrarVenda(char nome[][MAX_CARACTERES], float estoque[], float vendas[], int *qtdProdutos){
    char produto[MAX_CARACTERES];
    float inputVenda;
    int posicao;

    while(1){
        printf("\nNome do produto: ");
        if(lerString(produto, MAX_CARACTERES) == 1) break;
    }

    converteMaiuscula(produto);

    if((posicao = buscarProduto(produto, nome, qtdProdutos)) == -1){
        printf("\nProduto não encontrado, verifique se o nome do produto foi digitado corretamente.\n");
        return;
    }

    while(1){
        printf("Quantidade a ser vendida: ");
        if(lerFloat(&inputVenda) == 0){
            printf("\nResposta invalida, insira um número.\n");
            continue;
        }
        if(inputVenda <= 0){
            printf("\nValor invalido. Tente novamente.\n");
            continue;
        }
        break;
    }

    if(inputVenda > estoque[posicao]){
        printf("\nNão há estoque para esta venda. Só há %f no estoque.\n", estoque[posicao]);
        return;
    }

    vendas[posicao] += inputVenda;
    estoque[posicao] -= inputVenda;

    printf("\nVenda registrada com sucesso!\n");
}

void consultarProduto(char nome[][MAX_CARACTERES], float estoque[], float vendas[], int *qtdProdutos){
    char produto[MAX_CARACTERES];
    int posicao;

    while(1){
        printf("\nNome do produto: ");
        if(lerString(produto, MAX_CARACTERES) == 1) break;
    }

    converteMaiuscula(produto);

    if((posicao = buscarProduto(produto, nome, qtdProdutos)) == -1){
        printf("\nProduto não encontrado.\n");
        return;
    }

    printf("\nProduto encontrado.\n");
    printf("Nome: %s\nQuantidade em estoque: %.2f\nQuantidade vendida: %.2f\n", nome[posicao], estoque[posicao], vendas[posicao]);

}

void listarProdutos(char nome[][MAX_CARACTERES], float estoque[], float vendas[], int *qtdProdutos){
    printf("\nNome:                    |Estoque:   |Vendas:\n");
    for(int i=0; i<*qtdProdutos; i++){
        printf("%-25s|%-11.2f|%-11.2f\n", nome[i], estoque[i], vendas[i]);
    }
}

void relatorioEstoque(char nome[][MAX_CARACTERES], float estoque[], int *qtdProdutos){
    printf("\nTotal de produtos cadastrados: %d\n", *qtdProdutos);
    for(int i = 0; i < *qtdProdutos; i++){
        
    }
}

int main(){
    char rNome[QTD_MAX_PRODUTOS][MAX_CARACTERES]; // Nome dos produtos registrados
    float rEstoque[QTD_MAX_PRODUTOS] = {0}; // Quantidade em estoque dos produtos registrados.
    float rVendas[QTD_MAX_PRODUTOS] = {0}; // Quantidade vendido dos produtos registrados.
    int qtdProdutos = 0; // Quantidade de produtos cadastrados.
    int input;
    while(1){
        input = apresentarMenu();
        switch(input){
        case 1:
            cadastrar(rNome, rEstoque, &qtdProdutos);
            break;
        case 2:
            registrarVenda(rNome, rEstoque, rVendas, &qtdProdutos);
            break;
        case 3:
            consultarProduto(rNome, rEstoque, rVendas, &qtdProdutos);
            break;
        case 4:
            listarProdutos(rNome, rEstoque, rVendas, &qtdProdutos);
        default:
            break;
        }
        if(input == 0) break;
    }
    return 0;
}