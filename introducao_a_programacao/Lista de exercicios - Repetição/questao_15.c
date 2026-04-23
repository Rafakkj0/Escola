/*Escreva um programa que leia o código(matrícula) de um aluno e suas três notas. Calcule a média ponderada do aluno, considerando que o peso para a maior nota seja 5, a menor tem peso 2 e a outra peso 3. Mostre o código do aluno, suas três notas, a média calculada e uma mensagem "APROVADO" se a média for maior ou igual a 5 e "REPROVADO" se a média for menor que 5. Repita a operação até que o código lido seja negativo*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("-------------- Calculadora de notas --------------\n");
    
    int codigo, contador;
    float nota1, nota2, nota3, aux, media; //nota 1 é a meior e a nota 3 a menor
    
    while(1){
        printf("Forneça as informações pedidas.\nPara encerrar escreva um código negativo.\n\n");

        printf("> Código do aluno: ");
        scanf("%d",&codigo);
        if (codigo < 0) break;
        
        printf("> 1° Nota: ");
        scanf("%f", &nota1);

        printf("> 2º Nota: ");
        scanf("%f", &nota2);

        printf("> 3º Nota: ");
        scanf("%f", &nota3);

        if(nota1 < nota2){
            aux = nota1;
            nota1 = nota2;
            nota2 = aux;
        }
        if(nota1 < nota3){
            aux = nota1;
            nota1 = nota3;
            nota3 = aux;
        }
        if(nota2 < nota3){
            aux = nota2;
            nota2 = nota3;
            nota3 = aux;
        }
        media = ((nota1 * 5) + (nota2 * 3) + (nota3 * 2))/ (5 + 3 + 2);

        printf("--------------------------------------------------\n");
        printf("Boletim do aluno de código %d:\n\n",codigo);
        printf("Notas:\n");
        printf("> %.1f\n",nota1);
        printf("> %.1f\n",nota2);
        printf("> %.1f\n\n",nota3);
        printf("Média das notas: %.1f\n\n",media);
        printf("Situação do aluno: ");
        if(media >= 5) printf("APROVADO\n");
        else printf("REPROVADO\n");
        printf("--------------------------------------------------\n\n");
    }
    return 0;
}