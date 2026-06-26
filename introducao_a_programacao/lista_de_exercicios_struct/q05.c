// Utilize a estrutura Aluno do exercício1 e implemente as funções:
// void lerAluno(struct Aluno *a);
// void mostrarAluno(struct Aluno a);
// float calcularMedia(struct Aluno a);
// No programa principal, leia um aluno, calcule sua média e mostre seus dados.


#include <stdio.h>
#include <string.h>
#define TAM_MAX_NOME 101

void limpaBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

struct Aluno {
    int matricula;
    char nome[TAM_MAX_NOME];
    int nota1;
    int nota2;
};

void lerAluno(struct Aluno *a){
    printf("Matrícula: ");
    scanf("%d", a->matricula);
    limpaBuffer();

    printf("Nome: ");
    fgets(a->nome, TAM_MAX_NOME, stdin);
    int tam = strlen(a->nome);
    if(tam == TAM_MAX_NOME -1 && a->nome[tam-1] != '\n') limpaBuffer();
    else a->nome[tam-1] = '\0';

    printf("Nota 1: ");
    scanf("%d", a->nota1);
    limpaBuffer();
}

void mostrarAluno(struct Aluno a){

}

float calcularMedia(struct Aluno a){

}

int main(){
    return 0;
}