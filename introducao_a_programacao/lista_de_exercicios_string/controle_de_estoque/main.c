#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "mystring.h"

#define QTD_MAX_PRODUTOS 100

int pesquisaProdutos(char lista[],int qtdProdutos,char nome[]){
    int achou=-1, i;
    for(i=0; i < qtdProdutos && achou == 0; i++){
        if(strcmp(nome, lista[i]) == 0) achou = i;
    }
    return achou;
}


int main(){
    int selecao; // O que o usúario seleciona, no menu ou um produto
    int qtdProdutos = 0; // quantidade de produtos cadastrados no sistema

    char inputNome[50];                     // entrada do úsuario do nome do produto, antes de padronizar.
    float inputQtd;                          // entrada do úsuario de quantidade de produtos, tanto para o estoque, quanto para a venda
    char nomeProduto[QTD_MAX_PRODUTOS][50]; // Nome do produto no estoque
    float qtdEstoque[QTD_MAX_PRODUTOS];     // Quantidade de produtos ainda disponivel no estoque
    float qtdVendas[QTD_MAX_PRODUTOS];      // Quantidade de vendas realizadas
    
    do{
        printf("1 - Cadastrar Produto\t2 - Registrar Venda\t0 - Sair\n");
        printf("\n> ");
        scanf("%d", &selecao);
        limpaBuffer();

        switch (selecao)
        {
        case 1:
            // verificando se há espaço disposnivel para mais um produto.
            if(qtdProdutos == QTD_MAX_PRODUTOS){
                printf("\nQuantidade máxima de produtos atingida, não é possível adicionar um novo produto.\n");
                break;
            }

            printf("\nForneça o nome do produto: ");
            lerString(inputNome, 50);
            convertMaiuscula(inputNome);

            if(pesquisaProdutos(nomeProduto, QTD_MAX_PRODUTOS, inputNome) != -1){
                printf("\nProduto já cadastrado.\n");
                break;
            }
            
            strcpy(nomeProduto[qtdProdutos], inputNome); // Registrando produto

            while(1){
                printf("\nForneça a quantidade em estoque: ");
                scanf("%f", qtdEstoque[qtdProdutos]);
                limpaBuffer();
                if(qtdEstoque[qtdProdutos] < 0) printf("\n! - Quantidade invalida, tente novamente.\n");
                else break;
            }

            qtdProdutos++;
            break;
        case 2:
            if(qtdProdutos>0){
                printf("\nForneça o nome do produto: ");
                lerString(inputNome, 50);
                convertMaiuscula(inputNome);

                selecao = pesquisaProdutos(nomeProduto, QTD_MAX_PRODUTOS, inputNome);

                if(selecao == -1){
                    printf("\nEste produto ainda não foi cadastrado. Verifique se o nome foi escrito corretamente.\n");
                    break;
                }

                if(qtdEstoque[selecao] < 1){
                    printf("\nNão há estoque deste produto.\n");
                    break;
                }

                printf("\nForneça a quantidade que vai ser vendido: ");
                scanf("%f", inputQtd);

                if(inputQtd < qtdEstoque[selecao]){
                    printf("\nNão é possivel processar a venda por falta de estoque. ( No estoque há apenas %f )\n", qtdEstoque[selecao]);
                    break;
                }

                qtdEstoque[selecao] -= inputQtd;
                qtdVendas[selecao] += inputQtd;
                

            }else printf("\nNenhum produto cadastrado.\n");
            break;
        }

    }while(selecao != 0);

    return 0;
}