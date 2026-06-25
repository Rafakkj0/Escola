// Crie uma estrutura Aluno com os campos:
// • matrícula;
// • nome;
// • nota1;
// • nota2.
// Leia os dados de um aluno e exiba:
// • nome;
// • matrícula;
// • média das duas notas;
// • situação: Aprovado se a média for maior ou igual a 60 e Reprovado caso contrário.

#include <stdio.h>
#include <string.h>
#define TAM_MAX_NOME 101

void limpaBuffer(){
    while(getchar() != '\n');
}

struct Aluno {
    int matricula;
    char nome[TAM_MAX_NOME];
    int nota1;
    int nota2;
};

int main(){
    struct Aluno aluno;

    printf("\nForneça a as informações do aluno:\n");
    printf("Matrícula: ");
    scanf("%d", &aluno.matricula);
    limpaBuffer();

    printf("Nome: ");
    fgets(aluno.nome, TAM_MAX_NOME, stdin);
    int tam = strlen(aluno.nome);
    if(tam == TAM_MAX_NOME-1 && aluno.nome[tam-1] != '\n'){
        limpaBuffer();
    }
    else{
        aluno.nome[tam-1] = '\0';
    }

    printf("Nota 1: ");
    scanf("%d", &aluno.nota1);

    printf("Nota 2: ");
    scanf("%d", &aluno.nota2);

    // Mostrando resultados:

    printf("\n======================\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matrícula: %d\n", aluno.matricula);
    float media = (float)(aluno.nota1 + aluno.nota2)/2;
    printf("Média das notas: %.2f\n", media);
    printf("Situação: ");
    if(media >= 60) printf("Aprovado\n");
    else printf("Reprovado\n");
    printf("======================\n\n");

    return 0;
}