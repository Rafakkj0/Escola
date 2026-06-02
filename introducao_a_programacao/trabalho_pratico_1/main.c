#include <stdio.h>
#include "memoria.h"

#define TAM_MEMORIA 30

int main(){
    int memoria[TAM_MEMORIA] = {0};
    int totalAlocacoes[3] = {0}; // Para contar quantas vezes cada estratégia foi usada com sucesso
    int totalDesperdicios[3] = {0}; // Para somar o desperdício acumulado de cada estratégia
    
    // Entradas do úsuario //
    int resposta;
    int pid;
    int quantidade;

    // Outros //
    int resultado; // Variavel para armazernar o resultado de alguma função.


    while(1){
        printf("\n==================== Menu ====================\n");
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
                if((resposta >= 1 && resposta <=8) || resposta == 0) break;
                else printf("Valor invalido!\n");
            }
            else{
                while(getchar()!='\n');
                printf("\n[!] Erro: Valor invalido. Informe um número que corresponda as opções.\n");
            }
        }
        if(resposta != 0){
            switch (resposta){
            case 1:
                printf("================== Memória ===================");
                exibirMemoria(memoria, TAM_MEMORIA);
                break;  
            case 2:
                printf("========= Alocar Processo - First Fit ========");
                while(1){
                    printf("\nInforme o PID do processo: ");
                    pid = lerInteiroPositivo();
                    if(pid > 0) break;
                    else if(pid == -1) printf("\n[!] Erro: Valor invalido. O PID deve ser maior que 0.\n");
                    else if(pid == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                while(1){
                    printf("Informe a quantidade de blocos para o processo: ");
                    quantidade = lerInteiroPositivo();
                    if(quantidade > 0) break;
                    else if(quantidade == -1) printf("\n[!] Erro: Valor invalido. A quantidade de blocos deve ser maior que 0.\n");
                    else if(quantidade == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                resultado = alocarFirstFit(memoria, TAM_MEMORIA, pid, quantidade);
                if(resultado>=0){
                    totalDesperdicios[0] += resultado;
                    totalAlocacoes[0]++;
                }
                else if(resultado == -1) printf("\n[!] Erro: Espaço insulficiente.\n");
                else if(resultado == -2) printf("\n[!] Erro: Fragmentação externa.\n");
                else if(resultado == -3) printf("\n[!] Erro: Está PID já existe.\n");
                break;
            case 3:
                printf("========= Alocar Processo - Best Fit =========");
                while(1){
                    printf("\nInforme o PID do processo: ");
                    pid = lerInteiroPositivo();
                    if(pid > 0) break;
                    else if(pid == -1) printf("\n[!] Erro: Valor invalido. O PID deve ser maior que 0.\n");
                    else if(pid == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                while(1){
                    printf("Informe a quantidade de blocos para o processo: ");
                    quantidade = lerInteiroPositivo();
                    if(quantidade > 0) break;
                    else if(quantidade == -1) printf("\n[!] Erro: Valor invalido. A quantidade de blocos deve ser maior que 0.\n");
                    else if(quantidade == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                resultado = alocarBestFit(memoria, TAM_MEMORIA, pid, quantidade);
                if(resultado>=0){
                    totalDesperdicios[1] += resultado;
                    totalAlocacoes[1]++;
                }
                else if(resultado == -1) printf("\n[!] Erro: Espaço insulficiente.\n");
                else if(resultado == -2) printf("\n[!] Erro: Fragmentação externa.\n");
                else if(resultado == -3) printf("\n[!] Erro: Está PID já existe.\n");
                break;
            case 4:
                printf("======== Alocar Processo - Worst Fit =========");
                while(1){
                    printf("\nInforme o PID do processo: ");
                    pid = lerInteiroPositivo();
                    if(pid > 0) break;
                    else if(pid == -1) printf("\n[!] Erro: Valor invalido. O PID deve ser maior que 0.\n");
                    else if(pid == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                while(1){
                    printf("Informe a quantidade de blocos para o processo: ");
                    quantidade = lerInteiroPositivo();
                    if(quantidade > 0) break;
                    else if(quantidade == -1) printf("\n[!] Erro: Valor invalido. A quantidade de blocos deve ser maior que 0.\n");
                    else if(quantidade == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                resultado = alocarWorstFit(memoria, TAM_MEMORIA, pid, quantidade);
                if(resultado >=0){
                    totalDesperdicios[2] += resultado;
                    totalAlocacoes[2]++;
                }
                else if(resultado == -1) printf("\n[!] Erro: Espaço insulficiente.\n");
                else if(resultado == -2) printf("\n[!] Erro: Fragmentação externa.\n");
                else if(resultado == -3) printf("\n[!] Erro: Está PID já existe.\n");
                break;
            case 5:
                printf("============== Liberar processo ==============");
                while(1){
                    printf("\nInfome o PID do processo: ");
                    pid = lerInteiroPositivo();
                    if(pid > 0) break;
                    else if(pid == -1) printf("\n[!] Erro: Valor invalido. O PID deve ser maior que 0.\n");
                    else if(pid == -2) printf("\n[!] Erro: Valor invalido. Informe um número inteiro maior que 0.\n");
                }
                if(liberarProcesso(memoria, TAM_MEMORIA, pid) == -1) printf("\n[!] Erro: PID não encontrado na memória.\n");
                break;
            case 6:
                printf("============= Compactar memória ==============");
                compactarMemoria(memoria, TAM_MEMORIA);
                break;
            case 7:
                printf("============= Relatório da memória ===========\n");
                relatorioMemoria(memoria, TAM_MEMORIA);
                break;
            case 8:
                printf("======== Relatório de eficiência =============\n");
                relatorioEficiencia(totalAlocacoes, totalDesperdicios);
                break;
            default:
                break;
            }
        }
        else break;
    }
    return 0;
}
