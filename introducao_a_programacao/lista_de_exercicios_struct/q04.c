// Cadastre 10 pessoas com:
// • nome;
// • telefone;
// • idade.
// Leia um nome e procure essa pessoa no vetor. Se ela existir, exiba seu telefone e sua idade.
// Considere que os nomes são únicos.

#include <stdio.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_TELEFONE 20
#define QTD_PESSOAS 2

struct cadastro{
    char nome[TAM_MAX_NOME];
    char telefone[TAM_MAX_TELEFONE];
    int idade;
};

void limpaBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int busca(struct cadastro p[], int tam, char nome[]){
    for(int i = 0; i < tam; i++){
        if(strcmp(p[i].nome, nome) == 0) return i; 
    }
    return -1;
}

int main(){
    struct cadastro pessoa[QTD_PESSOAS];
    int qtdPessoas = 0;

    printf("Cadastre %d pessoas:\n", QTD_PESSOAS);

    for(int i = 0; i < QTD_PESSOAS; i++){
        while(1){
            printf("%dº pessoa:\n", i+1);
            printf("Nome: ");
            fgets(pessoa[i].nome, TAM_MAX_NOME, stdin);

            int tam = strlen(pessoa[i].nome);
            if(tam == TAM_MAX_NOME-1 && pessoa[i].nome[tam-1] != '\n') limpaBuffer();
            else pessoa[i].nome[tam-1] = '\0';

            if(busca(pessoa, qtdPessoas, pessoa[i].nome) == -1) break;
            else printf("\nPessoa já cadastrada!\n\n");
        }

        printf("Telefone: ");
        fgets(pessoa[i].telefone, TAM_MAX_TELEFONE, stdin);

        int tam = strlen(pessoa[i].telefone);
        if(tam == TAM_MAX_NOME-1 && pessoa[i].telefone[tam-1] != '\n') limpaBuffer();
        else pessoa[i].telefone[tam-1] = '\0';

        printf("Idade: ");
        scanf("%d", &pessoa[i].idade);
        limpaBuffer();

        qtdPessoas++;
    }

    printf("============ Buscar ===========\n");
    printf("Nome: ");
    char entrada[TAM_MAX_NOME];
    fgets(entrada, TAM_MAX_NOME, stdin);

    int tam = strlen(entrada);
    if(tam == TAM_MAX_NOME-1 && entrada[tam-1] != '\n') limpaBuffer();
    else entrada[tam-1] = '\0';

    int encontrada = busca(pessoa, qtdPessoas, entrada);
    if(encontrada != -1){
        printf("Pessoa encontrada!\n");
        printf("==================\n");
        printf("Nome: %s\n", pessoa[encontrada].nome);
        printf("Telefone: %s\n", pessoa[encontrada].telefone);
        printf("Idade: %d\n", pessoa[encontrada].idade);
        printf("==================\n");
    }
    else printf("Pessoa não encontrada!");

    return 0;
}