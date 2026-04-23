/*Faça um programa que leia um conjunto de 50 informações contendo, cada uma delas, a altura e
o sexo de uma pessoa (código=1, masculino código=2, feminino), calcule e mostre o seguinte:
a) a maior e a menor altura da turma;
b) a média da altura das mulheres;
c) a média da altura da turma;
d) A maior e a menor altura dos homens.*/
#include <stdio.h>
#include <locale.h>

#define QTD_PESSOAS 50

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    float altura;
    int sexo;
    //a
    float maior, menor;
    //b
    float somaMulheres = 0;
    int qtdMulheres = 0;
    //c
    int qtdTotal = 0;
    float somaTotal = 0;
    //d
    float maiorHomem, menorHomem;
    int qtdHomens;

    while(qtdTotal < QTD_PESSOAS){
        printf("\n\nAltura da %dº pessoa:\n-> ", qtdTotal + 1);
        scanf("%f",&altura);
        if(altura <= 0){
            printf("\nAltura inválida!\n");
            continue;
        }
        printf("\nQual o sexo da %dº pessoa?\n1 = Homem       2 = Mulher\n-> ", qtdTotal + 1);
        scanf("%d", &sexo);
        if(sexo != 1 && sexo != 2){
            printf("\nValor invalido!\n");
            continue;
        }
        //a
        if(qtdTotal == 0){
            maior = altura;
            menor = altura;
        }
        else{
            if(altura > maior){
                maior = altura;
            }
            else{
                if(altura < menor){
                    menor = altura;
                }
            }
        }
        //b
        if(sexo == 2){
            qtdMulheres++;
            somaMulheres += altura;
        }
        //d
        else{
            qtdHomens++;
            if(qtdHomens == 1){
                maiorHomem = altura;
                menorHomem = altura;
            }
            else{
                if(altura > maiorHomem){
                    maiorHomem = altura;
                }
                else{
                    if(altura < menorHomem){
                        menorHomem = altura;
                    }
                }
            }
        }
        //c
        somaTotal += altura;
        qtdTotal++;
    }
    printf("\nMaior altura da turma: %.2f\n", maior);
    printf("Menor altura da turma: %.2f\n", menor);
    printf("Média de altura da turma: %.2f\n", somaTotal / qtdTotal);
    if(qtdMulheres > 0) printf("Média de altura entre as mulheres: %.2f\n", somaMulheres / qtdMulheres);
    if(qtdHomens > 1){
        printf("Maior altura entre os homens: %.2f\n", maiorHomem);
        printf("Menor altura entre os homens: %.2f\n", menorHomem);
    }

    return 0;
}