#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float TEMP_C, TEMP_F;
    printf("Qual a temperatura em Fahrenheit?\nResposta: ");
    scanf("%f",&TEMP_F);
    TEMP_C = (TEMP_F - 32) * 5 / 9;
    printf("%f Graus Fahrenheit são %f Graus Centígrados.", TEMP_F, TEMP_C);
    return 0;
}