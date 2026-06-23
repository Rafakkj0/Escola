#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct {
    int matricula;
    char nome[100];
    float salario;
}TFuncionario;

int cadastrar(TFuncionario v[],int tamanho,int *ultimaPos);
void consultar(TFuncionario v[], int ultimaPos);
int excluir(TFuncionario v[],int *ultimaPos);
void listar(TFuncionario v[],int ultimaPos);
#endif
