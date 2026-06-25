// Cadastre 10 pessoas com:
// • nome;
// • telefone;
// • idade.
// Leia um nome e procure essa pessoa no vetor. Se ela existir, exiba seu telefone e sua idade.
// Considere que os nomes são únicos.

#include <stdio.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define QTD_PESSOAS 10

struct cadastro{
    char nome[TAM_MAX_NOME];
    int telefone;
    int idade;
};

void limpaBuffer(){
    while(getchar() != '\n');
}

int main(){
    struct cadastro pessoa[QTD_PESSOAS];

    printf("Cadastre %d pessoas:\n", QTD_PESSOAS);

    for(int i = 0; i < QTD_PESSOAS; i++){
        printf("%dº pessoa:\n");
        printf("Nome: ");
        fgets(pessoa[i].nome, TAM_MAX_NOME, stdin);
        int tam = strlen(pessoa[i].nome);
        if(tam == TAM_MAX_NOME-1 && pessoa[i].nome[tam-1] != '\n') limpaBuffer();
        else pessoa[i].nome[tam-1] = '\0';

        printf("Telefone: ");
        scanf("%d", &pessoa[i].telefone);
    }

    return 0;
}