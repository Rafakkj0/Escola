#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "mystring.h"
#define QUANTIDADE_MAXIMA 100

/* função auxiliar de busca linear
 percorre o vetor de nomes (só até a quantidade atual) e compara com a chave
 retorna o índice se achar, -1 se não achar*/
int pesquisa(char vNomes[][50],int tamanho,char chave[]){
    int i;
    for(i=0;i<tamanho;i++){
        if(strcmp(vNomes[i],chave)==0)
            return i;
    }
    return -1;
}

/*cadastra um novo produto
 recebe os vetores, a capacidade máxima (tamanho) e a quantidade atual (ponteiro),
 que referencia a variável no cliente(main) que deve ser alterada
retorna 1 se deu certo, 0 se falhou (limite atingido ou produto já existe)*/
int cadastro(char vNomes[][50],
            float vEstoque[],
            float vVendas[],
            int tamanho,//tamanho do vetor
            int *quantidade
            ){
    
    char nomeProduto[50];
    int i;
    
    // primeiro verifica se já atingiu o limite de 100 produtos
    if(*quantidade==QUANTIDADE_MAXIMA){
        return 0;
    }

    // lê o nome do produto, insiste até conseguir
    printf("Forneça o nome do produto a ser cadastrado:");
    while(lerString(nomeProduto,50)==0){
        printf("Forneça o nome do produto a ser cadastrado:");
    }
    converteMaiuscula(nomeProduto); // padroniza em maiúsculas pra facilitar comparação

    // verifica se já existe um produto com esse nome
    i = pesquisa(vNomes,*quantidade,nomeProduto);

    if(i != -1){
        printf("\nProduto já cadastrado!!!\n");
        return 0;
    }

    // se não existe, copia o nome para a primeira posição livre do vetor
    strcpy(vNomes[*quantidade],nomeProduto);

    // lê a quantidade inicial em estoque
    printf("Quantidade em Estoque:");
    while(lerFloat(&vEstoque[*quantidade])==0){
        printf("Quantidade em Estoque:");
    }
    
    // não aceita estoque negativo
    while(vEstoque[*quantidade]<0){
        printf("\nA quantidade em Estoque deve ser >=0!!!\n");
        printf("Quantidade em Estoque:");
        while(lerFloat(&vEstoque[*quantidade])==0){
            printf("Quantidade em Estoque:");
        }
    }

    // inicia o contador de vendas desse produto com zero
    vVendas[*quantidade]=0;
    (*quantidade)++; // importante: incrementa a quantidade total de produtos                    
    return 1;
}

/* registra uma venda de um produto existente
 recebe os vetores e a quantidade atual de produtos  retorna 1 se a venda foi realizada, 
 0 se deu algum erro*/
int registrarVenda(char vNomes[][50],
                   float vEstoque[],
                   float vVendas[],
                   int quantidade
    ){
    char nomeProduto[50];
    float qtdeVendida;
    int i;
    
    // primeiro verifica se existe pelo menos um produto cadastrado
    if(quantidade > 0){
        printf("Forneça o nome do produto a ser vendida:");
        while(lerString(nomeProduto,50)==0){
            printf("Forneça o nome do produto a ser vendida:");
        }
        converteMaiuscula(nomeProduto);

        // busca o produto pelo nome
        i = pesquisa(vNomes,quantidade,nomeProduto);
        
        if(i==-1){
            printf("\nProduto Não Cadastrado!!!\n");
            return 0;
        }

        // lê a quantidade a ser vendida
        printf("Forneça a Quantidade a ser Vendida:");
        while(lerFloat(&qtdeVendida)==0){
           printf("Forneça a Quantidade a ser Vendida:"); 
        }
        
        // não aceita quantidade negativa
        if(qtdeVendida<0){
            printf("\nA Quantidade Vendida não pode ser negativa!!!\n");
            return 0;
        }
        
        // verifica se tem estoque suficiente
        if(qtdeVendida<=vEstoque[i]){
           vEstoque[i] -= qtdeVendida;   // dá baixa no estoque
           vVendas[i] += qtdeVendida;    // acumula nas vendas do produto
           return 1;
        }
        else{
            // faltou o \n aqui no original, já corrigido
            printf("Quantidade em Estoque insuficiente!!!\n");
            return 0;
        }
        
    }
    else
        return 0;    
}

// programa principal
int main(){
    int quantidade=0, // representa o número de produtos cadastrados (vetor não totalmente preenchido)
        opcao;        // opção do menu
        
    // vetores paralelos: cada índice representa um produto
    float vendas[QUANTIDADE_MAXIMA];   // total vendido de cada produto
    float estoque[QUANTIDADE_MAXIMA];  // quantidade atual em estoque
    char nomes[QUANTIDADE_MAXIMA][50]; // nome de cada produto

    do{
        // menu principal - falta implementar as opções 3,4,5,6 do enunciado
        printf("\n1-Cadastro de Produto\n2-Registra Venda\n0-fim");
        printf("\nForneça sua opção:");
        while(lerInt(&opcao)==0){
            printf("Forneça sua opção:");
        }

       switch(opcao){
        case 1:
            if(cadastro(nomes,estoque,vendas,QUANTIDADE_MAXIMA,&quantidade)==1)
                printf("\nCadastro realizado!!\n");
            else
                printf("\nERRO\n");  // mensagem genérica, daria pra detalhar mais
            break;
        case 2:
            if(registrarVenda(nomes,estoque,vendas,quantidade)==1)
                printf("\nVenda Realizada com Sucesso!!\n");
            else
                printf("\nErro na Venda!!!!\n");
            break;
        // faltam os cases 3,4,5,6
        }
    }while(opcao!=0);
    return 0;

}