/*Implemente uma função soma_media(int a, int b, int *soma, float *media)
que calcule a soma e a média de dois números inteiros. Os resultados devem ser retornados por
meio dos ponteiros.*/

#include <stdio.h>

void soma_media(int a, int b, int *soma, float *media){
    *soma = a + b;
    *media = (a + b)/2.0;
}

int main(){
    int a, b, soma;
    float media;

    printf("\nFonrneça o valor de A e B: ");
    scanf("%d %d", &a, &b);

    soma_media(a, b, &soma, &media);

    printf("\nSoma dos dois números: %d\nMédia dos dois números: %.2f\n\n", soma, media);

    return 0;
}