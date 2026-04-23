#include <stdio.h>
#include <math.h>


int main(){
    float Raio, Area, PI;
    PI = 3.14159;
    printf("Qual o raio do seu círculo?\nResposta:");
    scanf("%f", &Raio);
    Area = PI * pow(Raio, 2);
    printf("O a área do circulo de raio %f é %.2f", Raio, Area);
    return 0;
}