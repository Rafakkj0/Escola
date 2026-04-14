/*Questão 22
Faça um programa que leia a, b, c, d, e que constituem o gabarito de uma prova de 5 questões.
Leia, a seguir, um número não determinado de conjuntos de 6 valores num, a1, b1, c1, d1, e1 onde
num é o número do aluno e os demais valores são as respostas dos alunos às 5 questões. Conte o
número de acertos e multiplique por 2. Escrever, para cada aluno, o seu número e a sua nota.*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int num, a1, b1, c1, d1, e1, i, resposta, soma;

    printf("Forneça as respostas corretas com o número respectivo a letra:\n1 -> A      2 -> B\n3 -> C      4 -> D\n5 -> E\n\n");
    printf("Questão 1: ");
    scanf("%d",&a1);
    printf("Questão 2: ");
    scanf("%d",&b1);
    printf("Questão 3: ");
    scanf("%d",&c1);
    printf("Questão 4: ");
    scanf("%d",&d1);
    printf("Questão 5: ");
    scanf("%d",&e1);

    if(a1>0 && a1<6 && b1>0 && b1<6 && c1>0 && c1<6 && d1>0 && d1<6){
        while(1){
            soma = 0;
            printf("\n-----------------------------------------------------------------------\n");
            printf("Número do aluno: ");
            scanf("%d",&num);

            for(i = 1 ; i <= 5 ; i++){
                printf("Questão %d: ", i);
                scanf("%d",&resposta);
                if(resposta > 0 && resposta < 6){
                    switch (i)
                    {
                    case 1:
                        if(resposta == a1){
                            soma++;
                        }
                        break;
                    case 2:
                        if(resposta == b1){
                            soma++;
                        }
                        break;
                    case 3:
                        if(resposta == c1){
                            soma++;
                        }
                        break;
                    case 4:
                        if(resposta == d1){
                            soma++;
                        }
                        break;
                    case 5:
                        if(resposta == e1){
                            soma++;
                        }
                        break;
                    default:
                        break;
                    }
                }
                else{
                    printf("\nResposta invalida, tente novamente.\n\n");
                    i--;
                }
            }
            printf("\nO aluno %d tirou %d.\n", num, soma*2);
        }
    }else printf("\n\nAlguma questão possui uma resposta invalida, execute o código novemente e tente de novo.\n\n");
    
    return 0;
}