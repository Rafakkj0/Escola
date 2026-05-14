#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float a, b, c, x;
    printf("\nA ∙ X + B = C\nQual o valor de A?\n");
    scanf("%f", &a);
    printf("Qual o valor de B?\n");
    scanf("%f", &b);
    printf("Qual o valor de C?\n");
    scanf("%f", &c);
    x = (c - b)/a;
    printf("O valor de X é %.2f.", x);
    return 0;
}