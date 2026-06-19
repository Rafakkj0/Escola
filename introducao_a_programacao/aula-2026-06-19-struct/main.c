/*Faça um programa que possua o menu:
1 – Cadastrar
2 – Consultar
3 – Excluir
4 - listar
5 – Fim
caso a opção selecionada seja:
1 – Permitir que se cadastre a matrícula, nome e salário de no máximo 30 funcionários.
Obs.:
a) A matrícula é única
b) Aceitar apenas valores positivos para o campo salário
2 – Pedir ao usuário uma valor e mostrar os dados do funcionário que possua matrícula igual ao valor
fornecido.
3 – Pedir ao usuário uma valor e excluir o funcionário que possua matrícula igual ao valor fornecido.
4 – Listar os dados de todos os funcionários
*/

#include <stdio.h>
#include <string.h>
#define MAX_FUNCIONARIOS 30

void limpaBuffer(){
    while(getchar() != '\n');
}


typedef struct funcionarios{
    int matricula;
    char nome[100];
    float salario;
}TFuncionario;

int main(){
    TFuncionario vf[MAX_FUNCIONARIOS];
    int numFuncionarios = 0;

    while(1){
        printf("\n1- Cadastrar\n2- Consultar\n3- Excluir\n4- Listar\n5- Fim\n>");
        int entrada;
        scanf("%d", &entrada);

        switch (entrada)
        {
        case 1: // Cadastrar funcionario
            if(numFuncionarios==MAX_FUNCIONARIOS){
                printf("\nNúmero máximo de funcionarios aingida!\n");
            }
            else{
                printf("\nForneça a matricula: ");
                int matricula;
                scanf("%d", &matricula);

                int achou = 0;
                for(int i = 0; i < numFuncionarios && achou == 0; i++){
                    if(matricula == vf[i].matricula) {
                        achou = 1;
                    }
                }
                if(achou == 1){
                    printf("\nMatricula já cadastrada!\n");
                    break;
                }
                else{
                    vf[numFuncionarios].matricula = matricula;
                    printf("Fornaça o nome: ");
                    limpaBuffer();
                    fgets(vf[numFuncionarios].nome, 100, stdin);
                    // Verificando se tem algo no buffer de entrada.
                    int tam = strlen(vf[numFuncionarios].nome);
                    if(vf[numFuncionarios].nome[tam-1]=='\n'){
                        vf[numFuncionarios].nome[tam-1]='\0';
                    }
                    else limpaBuffer();

                    printf("Forneça o salario: ");
                    scanf("%f", &vf[numFuncionarios].salario);

                    printf("\nFuncionario cadastrado com suceso.\n");
                    numFuncionarios++;
                }
            }
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            printf("\nFuncionarios cadastrados:\n");
            if(numFuncionarios == 0){
                printf("Nenhum funcionario cadastrado!\n");
            }
            else{
                for(int i=0; i < numFuncionarios; i++){
                    printf("Matricula: %d\n", vf[i].matricula);
                    printf("Nome: %s\n", vf[i].nome);
                    printf("Salário: R$%.2f\n", vf[i].salario);
                    printf("=====================\n");
                }
            }
            break;
        case 5:
            break;
        default:
            printf("\nValor invalido!\n");
            break;
        }
        if(entrada == 5) break;
    }
    return 0;
}