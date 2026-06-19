#include <stdio.h>
#include <string.h>
#include "funcionario.h"

typedef struct funcionarios{
    int matricula;
    char nome[100];
    float salario;
}TFuncionario;

void cadastrar(TFuncionario v[], int tamanho, int numFuncionarios){
    if(numFuncionarios==tamanho){
        printf("\nNúmero máximo de funcionarios aingida!\n");
    }
    else{
        printf("\nForneça a matricula: ");
        int matricula;
        scanf("%d", &matricula);

        int achou = 0;
        for(int i = 0; i < numFuncionarios && achou == 0; i++){
            if(matricula == v[i].matricula) {
                achou = 1;
            }
        }
        if(achou == 1){
            printf("\nMatricula já cadastrada!\n");
            return;
        }
        else{
            v[numFuncionarios].matricula = matricula;
            printf("Fornaça o nome: ");
            limpaBuffer();
            fgets(v[numFuncionarios].nome, 100, stdin);
            // Verificando se tem algo no buffer de entrada.
            int tam = strlen(v[numFuncionarios].nome);
            if(v[numFuncionarios].nome[tam-1]=='\n'){
                v[numFuncionarios].nome[tam-1]='\0';
            }
            else limpaBuffer();

            printf("Forneça o salario: ");
            scanf("%f", &v[numFuncionarios].salario);

            printf("\nFuncionario cadastrado com suceso.\n");
            numFuncionarios++;
        }
    }
}