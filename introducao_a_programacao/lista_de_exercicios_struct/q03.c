// Cadastre 8 alunos com:
// • matrícula;
// • nome;
// • curso;
// • média final.
// Leia uma matrícula e informe se o aluno foi encontrado.
// Caso seja encontrado, exiba todos os seus dados.

#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 2
#define TAM_MAX_NOME 100

struct Alunos{
    int matricula;
    char nome[TAM_MAX_NOME];
    char curso[TAM_MAX_NOME];
    float media;
};

void limpaBuffer(){
    while(getchar() != '\n');
}

int main(){
    struct Alunos aluno[QTD_ALUNOS];

    for(int i = 0; i < QTD_ALUNOS; i++){
        int tam;

        printf("\nForneça as informações do %dº aluno:\n", i+1);
        printf("Matrícula: ");
        scanf("%d", &aluno[i].matricula);
        limpaBuffer();

        printf("Nome: ");
        fgets(aluno[i].nome, TAM_MAX_NOME, stdin);
        tam = strlen(aluno[i].nome);
        if(tam == TAM_MAX_NOME - 1 && aluno[i].nome[tam-1] != '\n') limpaBuffer();
        else aluno[i].nome[tam-1] = '\0';

        printf("Curso: ");
        fgets(aluno[i].curso, TAM_MAX_NOME, stdin);
        tam = strlen(aluno[i].curso);
        if(tam == TAM_MAX_NOME - 1 && aluno[i].curso[tam-1] != '\n') limpaBuffer();
        else aluno[i].curso[tam-1] = '\0';

        printf("Média Final: ");
        scanf("%f", &aluno[i].media);
    }

    printf("\n=================\n");
    printf("Matrícula: ");
    int entrada;
    scanf("%d", &entrada);

    int achou = -1;
    for(int i = 0; i < QTD_ALUNOS; i++){
        if(entrada == aluno[i].matricula && achou == -1) achou = i;
    }

    printf("\nAluno encontrado:\n");
    if(achou != -1){
        printf("Nome: %s\n", aluno[achou].nome);
        printf("Matrícula: %d\n", aluno[achou].matricula);
        printf("Curso: %s\n", aluno[achou].curso);
        printf("Média Final: %.2f\n\n", aluno[achou].media);
    }
    else printf("\nAluno não encontrado.\n");

    return 0;
}