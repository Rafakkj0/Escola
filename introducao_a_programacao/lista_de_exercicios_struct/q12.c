// Faça um programa em linguagem C que apresente o seguinte menu de opções:
// 1 – Cadastro de Departamento
// 2 – Cadastro de Funcionários
// 3 – Consulta de Funcionários
// 4 – Funcionários de um Departamento
// 5 – Excluir Funcionário
// 6 – Excluir Departamento
// 7 – Fim
// O programa deverá ser devidamente modularizado por meio de funções.
// 1 – Cadastro de Departamento
// Permitir o cadastro de até 20 departamentos, contendo:
// • código (único)
// • nome (não pode ser vazio)
// • sigla
// 2 – Cadastro de Funcionários
// Permitir o cadastro de até 1000 funcionários, contendo:
// • matrícula (única)
// • nome (não pode ser vazio)
// • salário
// • código do departamento
// Regras:
// • A matrícula deve ser única;
// • O nome não pode ser vazio;
// • O salário deve ser maior que zero;
// • O código do departamento informado deve existir previamente cadastrado.
// 3 – Consulta de Funcionários
// Exibir a matrícula, nome e nome do departamento dos funcionários cujo nome inicie com um determinado prefixo informado pelo usuário.
// 4 – Funcionários de um Departamento
// Exibir todos os dados dos funcionários pertencentes a um departamento informado.
// 5 – Excluir Funcionário
// Remover um funcionário a partir de sua matrícula.
// 6 – Excluir Departamento
// Remover um departamento a partir de seu código, bem como todos os funcionários vinculados a ele.

#include <stdio.h>
#include <string.h>

#define MAX_DEPARTAMENTOS 20
#define MAX_FUNCIONARIOS 1000

#define TAM_MAX_NOME 101
#define TAM_MAX_SIGLA 5

typedef struct{
    int codigo;
    char nome[TAM_MAX_NOME];
    char sigla[TAM_MAX_SIGLA];
}depart;

typedef struct{
    int matricula;
    char nome[TAM_MAX_NOME];
    float salario;
    int codigoDepart;
}funci;

void limpaBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int apresentarMenu(){
    printf("\n======= Menu ======\n");
    printf("1 - Cadastrar Departamento\n");
    printf("2 - Cadastrar Funcionário\n");
    printf("3 - Consultar Funcionários\n");
    printf("4 - Consultar Funcionários de um Departamento\n");
    printf("5 - Excluir Funcionário\n");
    printf("6 - Excluir Departamento\n");
    printf("7 - Fim\n");
    while(1){
        printf("\n> ");
        int entrada;
        scanf("%d", &entrada);
        limpaBuffer();
        if(entrada >= 1 && entrada <= 7) return entrada;
        printf("Resposta inesperada, tente novamente.");
    }
}

int pesquisaCodigo(depart departamento[], int qtd, int codigo){
    for(int i = 0; i < qtd; i++){
        if(codigo == departamento[i].codigo) return i;
    }
    return -1;
}

int pesquisaMatricula(funci funcionario[], int qtd, int matricula){
    for(int i = 0; i < qtd; i++){
        if(matricula == funcionario[i].matricula) return i;
    }
    return -1;
}

void cadastrarDepartamento(depart departamento[], int *qtd){
    printf("\n====== Cadastro de Departamento ======\n");
    if(*qtd < MAX_DEPARTAMENTOS){
        while(1){
            printf("Código: ");
            scanf("%d", &departamento[*qtd].codigo);
            limpaBuffer();
            if(pesquisaCodigo(departamento, *qtd, departamento[*qtd].codigo) == -1) break;
            else printf("[!] Código já cadatrado, tente um outro.\n");
        }
        while(1){
            printf("Nome: ");
            fgets(departamento[*qtd].nome, TAM_MAX_NOME, stdin);
            int tam = strlen(departamento[*qtd].nome);
            if(tam == TAM_MAX_NOME -1 && departamento[*qtd].nome[tam-1] != '\n') limpaBuffer();
            else departamento[*qtd].nome[tam-1] = '\0';
            if(tam>1) break;
            else printf("[!] O campo nome não pode ser vazio, tente novamente.\n");
        }
        while(1){
            printf("Sigla: ");
            fgets(departamento[*qtd].sigla, TAM_MAX_SIGLA, stdin);
            int tam = strlen(departamento[*qtd].sigla);
            if(tam == TAM_MAX_SIGLA -1 && departamento[*qtd].sigla[tam-1] != '\n') limpaBuffer();
            else departamento[*qtd].sigla[tam-1] = '\0';
            if(tam>1) break;
            else printf("[!] O campo sigla não pode ser vazio, tente novamente.\n");
        }
        (*qtd)++;
        printf("\nCadastro de departamento realizdo com sucesso!\n");
    }
    else printf("[!] Número máximo de departamentos atingido.\n");
}

void cadastrarFuncionario(funci funcionario[], int *qtd, depart departamento[], int *qtdDepartamentos){
    printf("\n====== Cadastro de Funcionario ======\n");
    if(*qtd < MAX_FUNCIONARIOS){
        if(*qtdDepartamentos > 0){
            while(1){
                printf("Matrícula: ");
                scanf("%d", &funcionario[*qtd].matricula);
                limpaBuffer();
                if(pesquisaMatricula(funcionario, *qtd, funcionario[*qtd].matricula) == -1) break;
                else printf("[!] Matrícula já cadastrada, tente outra.\n");
            }
            while(1){
                printf("Nome: ");
                fgets(funcionario[*qtd].nome, TAM_MAX_NOME, stdin);
                int tam = strlen(funcionario[*qtd].nome);
                if(tam == TAM_MAX_NOME -1 && funcionario[*qtd].nome[tam-1] != '\n') limpaBuffer();
                else funcionario[*qtd].nome[tam-1] = '\0';
                if(tam>1) break;
                else printf("[!] O campo nome não pode ser vazio, tente novamente.\n");
            }
            while(1){
                printf("Salário: ");
                scanf("%f", &funcionario[*qtd].salario);
                limpaBuffer();
                if(funcionario[*qtd].salario > 0) break;
                else printf("[!] O salário deve ser maior que 0.");
            }
            while(1){
                printf("Código do departamento: ");
                scanf("%d", &funcionario[*qtd].codigoDepart);
                limpaBuffer();
                if(pesquisaCodigo(departamento, *qtdDepartamentos, funcionario[*qtd].codigoDepart) != -1) break;
                else printf("[!] Departamento inexistente.\n");
            }
            (*qtd)++;
            printf("\nCadastro do funcionário realizdo com sucesso!\n");
        }
        else printf("[!] Nenhum departamento cadastrado, cadastre um antes.\n");
    }
    else printf("[!] Número máximo de funcionários aingido.\n");
}


void consultarFuncionario(funci funcionario[], int qtd, depart departamento[], int qtdDepartamentos){
    printf("\n====== Consultar Funcionarios ======\n");
    char entrada;
    while(1){
        printf("Primeira letra do nome do funcionário: ");
        scanf("%c", &entrada);
        limpaBuffer();
        if(entrada != '\n') break;
        printf("[!] Algo deu errado, tente novamente.\n");
    }
    int achou = 0;
    for(int i = 0; i < qtd; i++){
        if(entrada == funcionario[i].nome[0]){
            achou = 1;
            printf("\nMatrícula: %d\n", funcionario[i].matricula);
            printf("Nome: %s\n", funcionario[i].nome);
            printf("Departamento: %s\n", departamento[pesquisaCodigo(departamento, qtdDepartamentos, funcionario[i].codigoDepart)].nome);
        }
    }
    if(achou == 0) printf("[!] Nenhum funcionário encontrado.\n");
}

void consultarDepartamento(depart departamento[], int qtdDepartamentos, funci funcionario[], int qtdFuncionarios){
    printf("\n====== Consultar Departamento ======\n");
    if(qtdDepartamentos > 0){
        if(qtdFuncionarios > 0){
            int entrada;
            printf("Código do departamento: ");
            scanf("%d", &entrada);
            limpaBuffer();
            int posDepartamento = pesquisaCodigo(departamento, qtdDepartamentos, entrada);
            if(posDepartamento != -1){
                int achou = 0;
                for(int i = 0; i < qtdFuncionarios; i++){
                    if(funcionario[i].codigoDepart == entrada){
                        achou = 1;
                        printf("\nMatrícula: %d\n", funcionario[i].matricula);
                        printf("Nome: %s\n", funcionario[i].nome);
                        printf("Salário: R$ %.2f\n", funcionario[i].salario);
                    }
                }
                if(achou == 0) printf("[!] Nenhum funcionário cadastrado neste departamento.\n");
            }
            else printf("[!] Departamento não encontrado.\n");
        }
        else printf("[!] Nenhum funcionário cadastrado.\n");
    }
    else printf("[!] Nenhum departamento cadastrado.\n");
}

void removerFuncionario(funci funcionario[], int *qtd){
    printf("\n====== Remover Funcionário ======\n");
    if(*qtd > 0){
        int entrada;
        printf("Matrícula: ");
        scanf("%d", &entrada);
        limpaBuffer();
        int posFuncionario = pesquisaMatricula(funcionario, *qtd, entrada);
        if(posFuncionario != -1){
            funcionario[posFuncionario] = funcionario[*qtd-1];
            (*qtd)--;
            printf("\nFuncionario excluído com sucesso.\n");
        }
        else printf("[!] Funcionário não encontrado.\n");
    }
    else printf("[!] Nenhum funcionário cadastrado.\n");
}

void removerDepartamento(depart departamento[], int *qtdDepartamentos, funci funcionario[], int *qtdFuncionarios){
    printf("\n====== Remover Departamento ======\n");
    if(*qtdDepartamentos > 0){
        int entrada;
        printf("Código: ");
        scanf("%d", &entrada);
        limpaBuffer();
        int posDepartamento = pesquisaCodigo(departamento, *qtdDepartamentos, entrada);
        if(posDepartamento != -1){
            departamento[posDepartamento] = departamento[*qtdDepartamentos-1];
            (*qtdDepartamentos)--;
            for(int i = 0; i < *qtdFuncionarios; i++){
                if(funcionario[i].codigoDepart == entrada){
                    funcionario[i] = funcionario[*qtdFuncionarios];
                    (*qtdFuncionarios)--;
                }
            }
        }
        else printf("[!] Departamento não encontrado.\n");
    }
    else printf("[!] Nenhum departamento cadastrado.\n");
}

int main(){
    depart departamento[MAX_DEPARTAMENTOS];
    funci funcionario[MAX_FUNCIONARIOS];

    int qtdDepartamentos = 0;
    int qtdFuncionarios = 0;

    while(1){
        int opcao = apresentarMenu();
        if(opcao == 7) break;
        switch(opcao){
            case 1:
                cadastrarDepartamento(departamento, &qtdDepartamentos);
                break;
            case 2:
                cadastrarFuncionario(funcionario, &qtdFuncionarios, departamento, &qtdDepartamentos);
                break;
            case 3:
                consultarFuncionario(funcionario, qtdFuncionarios, departamento, qtdDepartamentos);
                break;
            case 4:
                consultarDepartamento(departamento, qtdDepartamentos, funcionario, qtdFuncionarios);
                break;
            case 5:
            removerFuncionario(funcionario, &qtdFuncionarios);
                break;
            case 6:
            removerDepartamento(departamento, &qtdDepartamentos, funcionario, &qtdFuncionarios);
                break;
        }
    }
}