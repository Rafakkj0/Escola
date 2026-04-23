/*Questão 23
Foi feita uma pesquisa entre os habitantes de uma região. Foram coletados os dados de idade,
sexo (M/F) e salário. Faça um programa que informe:
a) a média de salário do grupo;
b) maior e menor idade do grupo;
c) quantidade de mulheres com salário até R$5000,00. 
Encerre a entrada de dados quando for digitada uma idade negativa.*/

#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    int idade, sexo, maiorIdade, menorIdade, qtdEntrevistados = 0, qtdMulheres5000 = 0;
    float somaSalario = 0, salario;

    while(1){
        printf("\nIdade: ");
        scanf("%d",&idade);
        if(idade < 0) break;

        printf("Sexo ( 1 para homem, 2 para mulher ): ");
        scanf("%d", &sexo);
        if(sexo != 1 && sexo != 2){
            printf("\nSexo incorreto, tente novamente.\n");
            continue;
        }

        printf("Sálario: R$");
        scanf("%f",&salario);
        if(salario < 0){
            printf("\nSalario incorreto, tente novamente.\n");
            continue;
        }
        somaSalario+=salario;
        qtdEntrevistados++;

        if(qtdEntrevistados == 1){
            menorIdade = idade;
            maiorIdade = idade;
        }
        else{
            if(idade > maiorIdade) maiorIdade = idade;
            else if(idade < menorIdade) menorIdade = idade;
        }

        if(sexo == 2 && salario <= 5000){
            qtdMulheres5000++;
        }
    }
    printf("\nMédia de salario na região: R$%.2f\n",somaSalario / qtdEntrevistados);
    printf("Maior idade: %d\n",maiorIdade);
    printf("Menor idade: %d\n",menorIdade);
    printf("Quantidade de mulheres com salário até R$5000,00: %d\n\n", qtdMulheres5000);
    
    return 0;
}