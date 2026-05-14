#include <stdio.h>
#include <windows.h>
#include <math.h>

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int sinal = 1, i;
    float s = 0, x;

    printf("\nQual o valor de X? ");
    scanf("%f", &x);

    for(i = 1 ; i <= 20 ; i++){
        s+= sinal*(1.0 / pow(x, i));
        sinal = -sinal;
    }
    printf("\n%f\n", s);
    return 0;
}