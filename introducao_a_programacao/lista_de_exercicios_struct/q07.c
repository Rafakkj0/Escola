// Crie uma estrutura Aluno com:
// • matrícula;
// • nome;
// • três notas;
// • média;
// • situação.
// Cadastre até 30 alunos.
// O programa deve apresentar um menu:
// 1 - Cadastrar aluno
// 2 - Listar alunos
// 3 - Consultar aluno por matrícula
// 4 - Exibir aprovados
// 5 - Exibir reprovados
// 0 - Sair
// A média deve ser calculada automaticamente. Considere aprovação com média maior ou igual a 60.

#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 3
#define QTD_NOTAS 3

#define TAM_MAX_NOME 101

struct Aluno{
    int matricula;
    char nome[TAM_MAX_NOME];
    float nota[QTD_NOTAS];
    float media;
    int aprovado;
};

void limpaBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int buscarMatricula(struct Aluno a[], int qtd, int mat){
    for(int i = 0; i < qtd; i++){
        if(mat == a[i].matricula) return i;
    }
    return -1;
}

int apresentarMenu(){
    printf("\n==========================================\n");
    printf("1-Cadastrar aluno       2-Listar alunos\n");
    printf("3-Consultar aluno       4-Exibir aprovados\n");
    printf("5-Exibir reprovados     0-Sair\n");
    while(1){
        printf("\n");
        printf("> ");
        int entrada;
        scanf("%d", &entrada);
        if(entrada>=0 && entrada <=5) return entrada;
        else printf("Resposta inesperada, tente novamente.\n");
    }
}

int cadastrarAluno(struct Aluno a[], int *qtd){
    while(1){
        printf("Matrícula: ");
        scanf("%d", &a[*qtd].matricula);
        limpaBuffer();
        if(buscarMatricula(a, *qtd, a[*qtd].matricula) == -1) break;
        printf("Matrícula já cadastrada!\n");
    }

    printf("Nome: ");
    fgets(a[*qtd].nome, TAM_MAX_NOME, stdin);
    int tam = strlen(a[*qtd].nome);
    if(tam == TAM_MAX_NOME-1 && a[*qtd].nome[tam-1] != '\n') limpaBuffer();
    else a[*qtd].nome[tam-1] = '\0';

    a[*qtd].media = 0;

    for(int i = 0; i < QTD_NOTAS; i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &a[*qtd].nota[i]);
        a[*qtd].media += a[*qtd].nota[i];
    }

    if(a[*qtd].media >= 60) a[*qtd].aprovado = 1;
    else a[*qtd].aprovado = 0;

    (*qtd)++;
    printf("\nAluno cadastrado com sucesso!\n");
}


int main(){
    struct Aluno a[QTD_ALUNOS];
    int qtdAlunos = 0;

    while(1){
        switch(apresentarMenu()){
            case 0:
                return 0;
            case 1:
                cadastrarAluno(a, &qtdAlunos);
                break;
        }
    }

    return 0;
}