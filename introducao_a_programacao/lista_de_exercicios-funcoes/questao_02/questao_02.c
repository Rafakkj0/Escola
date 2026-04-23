// Implemente uma função para calcular a área de um círculo.

#include <stdio.h>
#include <windows.h>

float areaCirculo(float raio){
    return 3.14 * raio * raio;
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    float raio;

    printf("\n\nForneça o raio do círculo: ");
    scanf("%f", &raio);

    printf("A área do círculo é: %.2f\n\n", areaCirculo(raio));
    return 0;
}