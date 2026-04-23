// Questão 02 
// Um radar registra velocidades dos veículos. O programa deve:
// 1. Ler velocidades inteiras.
// 2. Encerrar quando for digitado 0.
// 3. Classificar:
//    - Lenta: até 60
//    - Normal: 61 a 100
//    - Rápida: acima de 100
// Ao final mostrar:
// - Quantidade de veículos em cada categoria
// - A maior velocidade registrada
// - A menor velocidade registrada
// - Quantos veículos estavam acima de 80 km/h
#include <stdio.h>
#include <windows.h>

#define MAX_LENTA 60 // até 60
#define MAX_NORMAL 100 // de 60 até 100

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    printf("\nForneças as velocidades dos carros ( números positivos )\nPara encerrar e ver o resultado digite 0 ou um número negativo.\n");

    int entrada, qtdLenta = 0, qtdNormal = 0, qtdRapida = 0, maiorVelocidade, menorVelocidade, qtdAcima80 = 0; 

    while(1){
        printf("\n-> ");
        scanf("%d",&entrada);
        if(entrada <= 0) break;

        if(qtdLenta == 0 && qtdNormal == 0 && qtdRapida == 0){
            maiorVelocidade = entrada;
            menorVelocidade = entrada;
        }
        else{
            if(entrada > maiorVelocidade) maiorVelocidade = entrada;
            else if(entrada < menorVelocidade) menorVelocidade = entrada;
        }

        if(entrada <= MAX_LENTA){
            qtdLenta++;
        }
        else{
            if(entrada <= MAX_NORMAL){
                qtdNormal++;
            }
            else qtdRapida++;
        }

        if(entrada > 80) qtdAcima80++;
    }
    printf("\n-----------------------------------------------\n");
    if(qtdLenta != 0 || qtdNormal != 0 || qtdRapida != 0){
        printf("Quantidade de veiculos em velocidade lenta:  %d\n", qtdLenta);
        printf("Quantidade de veiculos em velocidade normal: %d\n", qtdNormal);
        printf("quantidade de veiculos em velocidade rápida: %d\n", qtdRapida);

        printf("\nMaior velocidade registrada: %d\n", maiorVelocidade);
        printf("Menor velocidade registrada: %d\n", menorVelocidade);

        printf("\nQuantidade de veiculos acima de 80 km/h: %d\n", qtdAcima80);
    }
    else printf("          Nenhum valor valido lido.\n");
    printf("-----------------------------------------------\n");
    return 0;
}