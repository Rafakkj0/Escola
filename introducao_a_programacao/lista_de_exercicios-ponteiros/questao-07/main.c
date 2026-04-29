// Crie   uma   função  void  retangulo(float  larg,  float  alt,  float  *area,
// float *perim) que calcule a área e o perímetro de um retângulo com base na largura e altura
// fornecidas.

#include <stdio.h>
#include <windows.h>

void retangulo(float larg, float alt, float *area, float *perim){
    if(larg > 0 && alt > 0){
        *area = larg * alt;
        *perim = 2 * larg + 2 * alt;
    }
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    float larg, alt, area, perim;

    printf("\nForneça a altura e a largura do retangulo para saber sua área e seu perimetro.\n");
    printf("Altura: ");
    scanf("%f", &alt);
    printf("Largura: ");
    scanf("%f", &larg);

    if(larg > 0 && alt > 0){
        retangulo(larg, alt, &area, &perim);
        printf("\nÁrea: %.3f\n", area);
        printf("Perímetro: %.3f\n", perim);
    }
    else printf("\nValores informados invalidos!\n");

    return 0;
}