#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "mystring.h"

#define QTD_MAX_PRODUTOS 100

int main(){
    int opcao; // resposta do usuario no menu
    int qtdProdutos = 0; // quantidade de produtos cadastrados no sistema

    char inputNome[50];                     // entrada do úsuario do nome do produto, antes de padronizar.
    char nomeProduto[QTD_MAX_PRODUTOS][50]; // Nome do produto no estoque
    float qtdEstoque[QTD_MAX_PRODUTOS];     // Quantidade de produtos ainda disponivel no estoque
    float qtdVendas[QTD_MAX_PRODUTOS];      // Quantidade de vendas realizadas

    int i, achou;
    
    do{
        printf("1 - Cadastrar Produto\t2 - Registrar Venda\t0 - Sair\n");
        printf("\n> ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
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

            //pesquisa sequencial
            achou=-1;
            for(i=0; i < qtdProdutos && achou == 0; i++){
                if(strcmp(inputNome, nomeProduto[i]) == 0) achou = i;
            }
            // Verificando se o produto foi encontrado
            if(achou != -1){
                printf("\nNão é possivel cadastrar este produto pois o ele já foi cadastrado\n");
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
                printf("Forneça o nome do produto: ");
                lerString(inputNome, 50);
                convertMaiuscula(inputNome);

                //pesquisa sequencial
                achou=0;
                for(i=0; i < qtdProdutos && achou == 0; i++){
                    if(strcmp(inputNome, nomeProduto[i]) == 0) achou = i;
                }
                // Verificando se o produto foi encontrado
                if(achou == -1){
                    printf("\nProduto não encontrado.\n");
                    break;
                }

                ///////////////////////////////////////////////

            }else printf("\nNenhum produto cadastrado.\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}