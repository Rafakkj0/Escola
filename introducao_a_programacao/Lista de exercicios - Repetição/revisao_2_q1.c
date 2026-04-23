/*Questão 01 
Um sensor registra níveis de energia detectados. O programa deve:
1. Ler números inteiros positivos.
2. A leitura termina quando for digitado -1.
3. Para cada valor:
   - Verificar se é par
   - Verificar se é múltiplo de 5
Ao final mostrar:
- Quantidade total de valores lidos
- Quantidade de números pares
- Quantidade de múltiplos de 5
- O maior valor lido
- O menor valor lido*/
#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    int entrada, qtdValores = 0, qtdPares = 0, qtdMultiplos5 = 0, maiorValor, menorValor;

    printf("\nForneça apenas valores positivos.\nPra encerrar e ver os resultados digite 0 ou um número negativo.\n");
    while(1){
        printf("\n-> ");
        scanf("%d",&entrada);
        if(entrada <= 0) break;

        qtdValores++;

        if((entrada % 2) == 0) qtdPares++;

        if((entrada % 5) == 0) qtdMultiplos5++;

        if(qtdValores == 1){
            maiorValor = entrada;
            menorValor = entrada;
        }
        else{
            if(entrada > maiorValor) maiorValor = entrada;
            else if (entrada < menorValor) menorValor = entrada;
        }
    }
    printf("\n-----------------------------------\n");
    if(qtdValores > 0){
        printf("Quantidade de valores lidos:____%d\n", qtdValores);
        printf("Quantidade de pares:____________%d\n", qtdPares);
        printf("Quantidade de multiplos de 5:___%d\n", qtdMultiplos5);
        printf("Maior valor lido:_______________%d\n", maiorValor);
        printf("Menor valor lido:_______________%d\n", menorValor);
    }
    else printf("Nenhum valor valido inserido.");
    printf("-----------------------------------\n");
    return 0;
}