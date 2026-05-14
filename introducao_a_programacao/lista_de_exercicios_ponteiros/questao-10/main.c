/*Implemente uma função  que calcule as raízes de uma equação do segundo grau ax² + bx + c = 0. A
função deve receber os coeficientes a, b e c e armazenar as raízes reais em dois ponteiros (x1 e x2).
Deve verificar se a ≠ 0 e se o  Δ = b² − 4ac é maior ou igual a zero.  A função deve retornar 1 se o
cálculo for possível e 0 se não houver raízes reais ou se não for uma equação do segundo grau*/

#include <stdio.h>
#include <math.h>

int calRaizes(float a, float b, float c, float *raiz1, float *raiz2){
    if(a != 0){
        float delta;
        delta = b*b-4*a*c;
        if(delta >= 0){
            *raiz1 = (-b + sqrt(delta)) / (2 * a);
            *raiz2 = (-b - sqrt(delta)) / (2 * a);
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main(){
    float a, b, c, raiz1, raiz2;

    printf("Calculadora de equação de segundo grau:\n");
    printf("Valor de A: ");
    scanf("%f", &a);
    printf("Valor de B: ");
    scanf("%f", &b);
    printf("Valor de C: ");
    scanf("%f", &c);

    if(calRaizes(a, b, c, &raiz1, &raiz2) != 0){
        printf("\nResultados:\n");
        printf("1º Raiz: %f", raiz1);
        printf("2º Raiz: %f", raiz2);
    }
    else printf("\nNão há raízes reais ou a equação não é uma equação do segundo grau.\n");

    return 0;
}