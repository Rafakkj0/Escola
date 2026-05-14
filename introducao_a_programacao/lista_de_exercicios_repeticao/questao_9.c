/*A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o
salário e número de filhos. A prefeitura deseja saber:
a) média do salário da população;
b) média do número de filhos;
c) maior salário;
d) percentual de pessoas com salário até R$2000,00.
O final da leitura de dados se dará com a entrada de um salário negativo.*/

#include <stdio.h>
#include <locale.h>

#define VULNERAVEL 2000.0 // valor do salario para ser considerado VULNERAVEL.

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    float salario, maiorSalario = 0, somaSalario = 0;
    int numFilhos, qtdEntrevistados = 0, somaNumFilhos = 0, qtdVulneraveis = 0;
    char fazerConta = 1;

    printf("-------------------- Censo 2026 --------------------\nForneça um salário negativo para encerrar o programa.\n\n");

    printf("Entrevista N°%d\n", qtdEntrevistados + 1);
    printf("Salário do entrevistado: R$");
    scanf("%f",&salario);
    if(salario >= 0){
        printf("Quantidade de filhos: ");
        scanf("%d", &numFilhos);
        if(numFilhos < 0){
            printf("Forneça uma quantidade real.\n\n");
            fazerConta = 0;
        }
    }
    while(salario >= 0){
        if(fazerConta == 1){
            // Média do salario da população
            somaSalario += salario;
            // Média do número de filhos
            somaNumFilhos += numFilhos;
            // Maior salário
            if(qtdEntrevistados == 0) maiorSalario = salario;
            else{
                if(salario > maiorSalario){
                    maiorSalario = salario;
                }
            }
            //Percentual de pessoas vulneraveis
            if(salario <= VULNERAVEL){
                qtdVulneraveis++;
            }
            qtdEntrevistados++;
        }
        fazerConta = 1;
        printf("Entrevista N°%d\n", qtdEntrevistados + 1);
        printf("Salário do entrevistado: R$");
        scanf("%f",&salario);
        if(salario >= 0){
            printf("Quantidade de filhos: ");
            scanf("%d", &numFilhos);
            if(numFilhos < 0){
                printf("Forneça uma quantidade real.\n\n");
                fazerConta = 0;
            }
        }
    }
    printf("---------------------------------------------------------------\n");
    if(qtdEntrevistados != 0){
        printf("Média do salario da população: R$%.2f\n", somaSalario / qtdEntrevistados);
        printf("Média da quantidade de filhos: %.1f filhos\n", (float)somaNumFilhos / qtdEntrevistados);
        printf("Maior salário: R$%.2f\n", maiorSalario);
        if(qtdVulneraveis != 0){
            printf("Porcentage de familias com salário até R$%.2f: %.2f%%\n", VULNERAVEL, ((float)qtdVulneraveis / qtdEntrevistados)*100);
        }
        else printf("Nenhuma família está em estado de vulnerabilidade.\n");
        
    }
    else{
        printf("Nenhuma informação foi inserida,então nenhum calculo foi feito.\n");
    }
    printf("---------------------------------------------------------------\n");
    return 0;
}