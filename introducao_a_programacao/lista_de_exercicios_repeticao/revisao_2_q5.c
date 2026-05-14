// Questão 05
// Uma estação mede temperaturas. 
// O programa deve:
// 1. Ler temperaturas reais.
// 2. Encerrar quando for digitado 999.
// 3. Classificar:
//    - Baixa: abaixo de 100
//    - Média: 100 a 300
//    - Alta: acima de 300
// Ao final mostrar:
// - Quantas temperaturas em cada tipo
// - A média geral
// - A maior temperatura de cada classe
// - A menor temperatura de cada classe
// - A maior temperatura geral
// - A menor temperatura geral
// - Quantas temperaturas ficaram entre 150 e 250
#include <stdio.h>
#include <windows.h>

#define MIN_MEDIA 100
#define MAX_MEDIA 300

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    int entrada,
    qtdBaixa = 0, qtdMedia = 0, qtdAlta = 0,
    somaTemperatura = 0,
    maiorBaixa, maiorMedia, maiorAlta, maiorTemperatura,
    menorBaixa, menorMedia, menorAlta, menorTemperatura,
    qtd150a250 = 0;
    
    printf("\nForneça as temperaturas, para ecerrar o código e visalizar os resultados digite \"999\".\n");

    while(1){
        printf("\n-> ");
        scanf("%d", &entrada);
        if(entrada == 999) break;

        somaTemperatura += entrada;

        if(qtdBaixa == 0 && qtdMedia == 0 && qtdAlta == 0){
            maiorTemperatura = entrada;
            menorTemperatura = entrada;
        }
        else{
            if(entrada > maiorTemperatura) maiorTemperatura = entrada;
            else if(entrada < menorTemperatura) menorTemperatura = entrada;
        }

        if(entrada < MIN_MEDIA){
            qtdBaixa++;
            if(qtdBaixa == 1){
                maiorBaixa = entrada;
                menorBaixa = entrada;
            }
            else{
                if(entrada > maiorBaixa) maiorBaixa = entrada;
                else if(entrada < menorBaixa) menorBaixa = entrada;
            }
        }
        else{
            if(entrada <= MAX_MEDIA){
                qtdMedia++;
                if(qtdMedia == 1){
                    maiorMedia = entrada;
                    menorMedia = entrada;
                }
                else{
                    if(entrada > maiorMedia) maiorMedia = entrada;
                    else if(entrada < menorMedia) menorMedia = entrada;
                }
            }
            else{
                qtdAlta++;
                if(qtdAlta == 1){
                    maiorAlta = entrada;
                    menorAlta = entrada;
                }
                else{
                    if(entrada > maiorAlta) maiorAlta = entrada;
                    else if(entrada < menorAlta) menorAlta = entrada;
                }
            }
        }
        if(entrada >= 150 && entrada <= 250) qtd150a250++;
    }
    if(qtdBaixa != 0 || qtdMedia != 0 || qtdAlta != 0){
        printf("\nQuantidade de temperaturas BAIXAS registrada: %d\n", qtdBaixa);
        printf("Quantidade de temperaturas MÉDIAS registrada: %d\n", qtdMedia);
        printf("Quantidade de temperaturas ALTAS registrada: %d\n", qtdAlta);
        printf("Média das temperaturas em geral: %.1f\n", (float)somaTemperatura / (qtdMedia + qtdBaixa + qtdAlta));
        printf("Meior temperatura BAIXA registrada: %d\n", maiorBaixa);
        printf("Meior temperatura MÉDIA registrada: %d\n", maiorMedia);
        printf("Meior temperatura ALTA registrada: %d\n", maiorAlta);
        printf("Menor temperatura BAIXA registrada: %d\n", menorBaixa);
        printf("Menor temperatura MÉDIA registrada: %d\n", menorMedia);
        printf("Menor temperatura ALTA registrada: %d\n", menorAlta);
        printf("Maior temperatura registrada: %d\n", maiorTemperatura);
        printf("Menor temperatura registrada: %d\n", menorTemperatura);
        printf("Quantidade de temperaturas registradas entre 150 e 250: %d\n\n", qtd150a250);
    }
    else printf("\nNenhum valor valido lido, portanto não há resultados.\n\n");
    return 0;
}