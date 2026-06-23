#include <stdio.h>
#include <string.h>
#include "funcionario.h"
void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c!='\n');
}

int pesquisa(TFuncionario v[], int ultimaPos, int mat){
    int i=0;
    int achou=0;
    while(i<=ultimaPos && achou==0){
        if(v[i].matricula==mat)
            achou=1;
        else
            i++;
    }
    if(achou == 1) return i;
    else return -1;
}

int cadastrar(TFuncionario v[],int tamanho,int *ultimaPos){
    int mat,achou,i,t;
    if(*ultimaPos==tamanho-1){
        printf("\nVetor Cheio\n");
        return 0;
    }
    else{
        printf("Forneça a matrícula:");
        scanf("%d",&mat);
        if(pesquisa(v, *ultimaPos, mat) != -1){
            printf("\nMatrícula Repetida!!!\n");
            return 0;
        }
        else{
            (*ultimaPos)++;
            v[*ultimaPos].matricula=mat;
            printf("Forneça o nome:");
            limpaBuffer();
            fgets(v[*ultimaPos].nome,100,stdin);
            //verificando se tem algo no buffer de entrada
            t = strlen(v[*ultimaPos].nome);
            if(v[*ultimaPos].nome[t-1]=='\n')
                v[*ultimaPos].nome[t-1]='\0';
            else
                limpaBuffer();
            printf("Forneça o salário:");
            scanf("%f",&v[*ultimaPos].salario);
            return 1;
        }
    }
}

void consultar(TFuncionario v[], int ultimaPos){
    int mat;
    //verificando se tem pelo menos um funcionário cadastrado
    if(ultimaPos>=0){
        printf("\nForneça a matricula: ");
        scanf("%d", &mat);
        int posFuncionario = pesquisa(v, ultimaPos, mat);
        if(posFuncionario != -1){
            printf("\nDados do funconario:\n");
            printf("Matrícula: %d\n",v[posFuncionario].matricula);
            printf("Nome: %s\n",v[posFuncionario].nome);
            printf("Salário: %.1f\n",v[posFuncionario].salario);
        }
        else{
            printf("\nFuncionario não encontrado!\n");
        }
    }
    else
        printf("\nNenhum Funcionário Cadastrado!!!\n");
}

int excluir(TFuncionario v[],int *ultimaPos){
    int mat;
    if(*ultimaPos>=0){
        printf("\nForneça a matricula: ");
        scanf("%d", &mat);
        int posFuncionario = pesquisa(v, *ultimaPos, mat);
        if(posFuncionario != -1){
            if(posFuncionario != *ultimaPos) v[posFuncionario] = v[*ultimaPos];
            (*ultimaPos)--;
            return 0;
        }
        else{
            printf("\nFuncionario não encontrado!\n");
        }
    }
    else
        printf("\nNenhum Funcionário Cadastrado!!!\n");
    return 1;
}

void listar(TFuncionario v[],int ultimaPos){
    int i;
    //verificando se tem pelo menos um funcionário cadastrado
    if(ultimaPos>=0){
        printf("\nFuncionários Cadastrados\n");
        for(i=0;i<=ultimaPos;i++){
            printf("Matrícula: %d\n",v[i].matricula);
            printf("Nome: %s\n",v[i].nome);
            printf("Salário: %.1f\n",v[i].salario);
        }
    }
    else
        printf("\nNenhum Funcionário Cadastrado!!!\n");
}