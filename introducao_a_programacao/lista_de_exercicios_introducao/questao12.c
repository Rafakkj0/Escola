#include <stdio.h>

int main() {
    int r,a1,n;
    printf("--- Calculadora de progressao aritimetica. ---\nForneca a razao da P.A.: ");
    scanf("%d",&r);
    printf("\nAgora, forneca o primeiro termo da P.A.: ");
    scanf("%d",&a1);
    printf("Sua P.A esta ficando assim:\n%d, %d, %d, %d, %d...\n", a1 + ((1 - 1) * r), a1 + ((2 - 1) * r), a1 + ((3 - 1) * r), a1 + ((4 - 1) * r), a1 + ((5 - 1) * r));
    printf("Qual o termo da P.A. voce quer? ");
    scanf("%d",&n);
    printf("O %dº termo e o numero %d", n, a1 + ((n -1) * r));
    return 0;
}
