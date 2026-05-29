#include <stdio.h>

#define SIZE_MEMORIA 30

int apresentarMenu(){
    int resposta;
    printf("\n--------------------------------\n");
    printf("1 - Exibir memória\n");
    printf("2 - Alocar processo (First Fit)\n");
    printf("3 - Alocar processo (Best Fit)\n");
    printf("4 - Alocar processo (Worst Fit)\n");
    printf("5 - Liberar processo\n");
    printf("6 - Compactar memória\n");
    printf("7 - Relatório da memória\n");
    printf("8 - Relatório de eficiência\n");
    printf("0 - Sair\n\n");
    while(1){
        printf("> ");
        if(scanf("%d", &resposta)!=0){
            if((resposta >= 1 && resposta <=8) || resposta == 0) return resposta;
            else printf("Valor invalido!\n");
        }
        else{}
    }
}

int main(){
    int memoria[SIZE_MEMORIA] = {0};
    int totalAlocacoes[3]; // Para contar quantas vezes cada estratégia foi usada com sucesso
    int totalDesperdicios[3]; // Para somar o desperdício acumulado de cada estratégia

    apresentarMenu();

    return 0;
}