/*Faça um programa que possua o menu:
1 – Cadastrar
2 – Consultar
3 – Excluir
4 - listar
5 – Fim
caso a opção selecionada seja:
1 – Permitir que se cadastre a matrícula, nome e salário de no 
máximo 30 funcionários.
Obs.:
a) A matrícula é única
b) Aceitar apenas valores positivos para o campo salário

2 – Pedir ao usuário uma valor e mostrar os dados do funcionário que 
possua matrícula igual ao valor fornecido.

3 – Pedir ao usuário uma valor e excluir o funcionário que possua 
matrícula igual ao valor fornecido.

4 – Listar os dados de todos os funcionários
*/
#include <stdio.h>
#include <string.h>
#include "funcionario.h"
#define NUMERO_MAXIMO_FUNCIONARIOS 1000
int main(){
    TFuncionario vf[NUMERO_MAXIMO_FUNCIONARIOS];
    int ultimaPosicao=-1,opcao;
    do{
        printf("\n\n1-Cadastrar\n2-Consultar\n3-Excluir\n4-Listar\n5-Fim");
        printf("\nFoneça sua opção:");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                if(cadastrar(vf,NUMERO_MAXIMO_FUNCIONARIOS,&ultimaPosicao)==1)
                    printf("Funcionário Cadastrado co Sucesso!!!\n");
                else    
                    printf("\nNão foi possível realizar o cadastro!!!\n");
                break;
            case 2:
                consultar(vf, ultimaPosicao);
                break;
            case 3:
                if(excluir(vf, &ultimaPosicao) == 0){
                    printf("\nFuncionario excluido com sucesso.\n");
                }
                break;
            case 4:
                listar(vf,ultimaPosicao);
                break;
        }
    }while(opcao != 5);
    return 0;
}


