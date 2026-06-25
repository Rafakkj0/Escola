// Utilize a estrutura Aluno e cadastre 5 alunos.
// Ao final, exiba:
// • os dados de todos os alunos;
// • a média da turma;
// • o nome do aluno com a maior média.

#include <stdio.h>
#include <string.h>
#define TAM_MAX_NOME 100
#define QTD_ALUNOS 5

void limpaBuffer(){
    while(getchar() != '\n');
}

struct Aluno {
    int matricula;
    char nome[TAM_MAX_NOME];
    int nota1;
    int nota2;
    float media;
};

int main(){
    struct Aluno aluno[QTD_ALUNOS];
    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nForneça a as informações do %dº aluno:\n", i+1);
        printf("Matrícula: ");
        scanf("%d", &aluno[i].matricula);
        limpaBuffer();

        printf("Nome: ");
        fgets(aluno[i].nome, TAM_MAX_NOME, stdin);
        int tam = strlen(aluno[i].nome);
        if(tam == TAM_MAX_NOME-1 && aluno[i].nome[tam-1] != '\n'){
            limpaBuffer();
        }
        else{
            aluno[i].nome[tam-1] = '\0';
        }

        printf("Nota 1: ");
        scanf("%d", &aluno[i].nota1);

        printf("Nota 2: ");
        scanf("%d", &aluno[i].nota2);

        aluno[i].media = (float)(aluno[i].nota1 + aluno[i].nota2)/2;
    }

    float mediaTurma = 0;
    for(int i = 0; i < QTD_ALUNOS; i++) mediaTurma += aluno[i].media;
    mediaTurma /= QTD_ALUNOS;

    int maiorMedia = aluno[0].media;
    for(int i = 1; i < QTD_ALUNOS; i++){
        if(aluno[i].media > maiorMedia) maiorMedia = aluno[i].media;
    }

    // Mostrando resultados:
    printf("\nDados de todos os alunos:");
    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nNome: %s\n", aluno[i].nome);
        printf("Matrícula: %d\n", aluno[i].matricula);
        printf("Média das notas: %.2f\n", aluno[i].media);
        printf("Situação: ");
        if(aluno[i].media >= 60) printf("Aprovado\n");
        else printf("Reprovado\n");
    }

    printf("\nMédia da turma: %f\n", mediaTurma);

    printf("\nAluno(s) com maior média:\n");
    for(int i = 0; i < QTD_ALUNOS; i++){
        if(aluno[i].media == maiorMedia){
            printf("Nome: %s\n", aluno[i].nome);
            printf("Matrícula: %d\n\n", aluno[i].matricula);
        }
    }

    return 0;
}