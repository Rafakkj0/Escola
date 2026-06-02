#include <stdio.h>
#include "memoria.h"

void exibirMemoria(int memoria[], int tamanho){
    int qtdLivres = 0;
    int qtdOcupados = 0;
    printf("\n[");
    for(int i=0; i<tamanho; i++){
        printf("%d", memoria[i]);
        if(i != tamanho-1) printf("] [");
        if(memoria[i] == 0) qtdLivres++;
        else qtdOcupados++;
    }
    printf("]\n\n");
    printf("Quantidade de blocos livres: %d\n", qtdLivres);
    printf("Quantidade de blocos ocupados: %d\n", qtdOcupados);
}

int alocarFirstFit(int memoria[], int tamanho, int pid, int quantidade){
    int possivelPos;
    int cont = 0;
    if(buscarPID(memoria, tamanho, pid) == -1){
        for(int i=0; i<tamanho; i++){
            if(memoria[i]==0){
                cont=0;
                possivelPos=i;
                while(i<tamanho && memoria[i]==0){
                    cont++;
                    i++;
                }
                if(cont>=quantidade){
                    for(int k=possivelPos; k<possivelPos+quantidade; k++) memoria[k] = pid;
                    return cont - quantidade;
                }
            }
        }
        if(contarBlocosVazios(memoria, tamanho) < quantidade) return -1; // Espaço insulficiente
        else return -2; // fragmantação externa
    }
    else return -3; // PID já existe.
}

int alocarBestFit(int memoria[], int tamanho, int pid, int quantidade){
    int possivelPos;
    int EnderecoDoMenor = -1;
    int TamanhoDoMenor = tamanho;
    int cont = 0;
    if(buscarPID(memoria, tamanho, pid) == -1){
        for(int i=0; i < tamanho; i++){
            if(memoria[i] == 0){
                cont = 0;
                possivelPos = i;
                while(i<tamanho && memoria[i]==0){
                    cont++;
                    i++;
                }
                if(cont >= quantidade && cont < TamanhoDoMenor){
                    EnderecoDoMenor = possivelPos;
                    TamanhoDoMenor = cont;
                }
            }
        }
        if(EnderecoDoMenor == -1){
            if(contarBlocosVazios(memoria, tamanho) < quantidade) return -1; // Espaço insulficiente
            else return -2; // fragmentação externa;
        }
        else{
            for(int k = EnderecoDoMenor; k<EnderecoDoMenor+quantidade; k++) memoria[k] = pid;
            return TamanhoDoMenor-quantidade;
        }    
    }
    else return -3; // PID já existe
}

int alocarWorstFit(int memoria[], int tamanho, int pid, int quantidade){
    int possivelPos;
    int enderecoDoMaior = -1;
    int tamanhoDoMaior = 0;
    int cont = 0;
    if(buscarPID(memoria, tamanho, pid) == -1){
        for(int i=0; i<tamanho; i++){
            if(memoria[i] == 0){
                cont = 0;
                possivelPos = i;
                while(i<tamanho && memoria[i] == 0){
                    cont++;
                    i++;
                }
                if(cont >= quantidade && cont > tamanhoDoMaior){
                    enderecoDoMaior = possivelPos;
                    tamanhoDoMaior = cont;
                }
            }
        }
        if(enderecoDoMaior == -1){
            if(contarBlocosVazios(memoria, tamanho) < quantidade) return -1; // Espaço insulficiente
            else return -2; // fragmentação externa
        }
        else{
            for(int k=enderecoDoMaior; k<enderecoDoMaior+quantidade; k++) memoria[k] = pid;
            return tamanhoDoMaior - quantidade;
        }
    }
    else return -3; // PID já existe
}

int liberarProcesso(int memoria[], int tamanho, int pid){
    int posPid;
    if((posPid = buscarPID(memoria, tamanho, pid)) >= 0){
        for(int i = posPid; i < tamanho && memoria[i] == pid; i++) memoria[i] = 0;
        return 0;
    }
    else return -1; // PID não encontrado.
}

void compactarMemoria(int memoria[], int tamanho){
    int r = verificarCompactacao(memoria, tamanho);
    if(r == 0){
        int posVazia;
        for(int i=0; i<tamanho; i++){
            if(memoria[i] == 0){
                posVazia = i;
                while(i<tamanho && memoria[i] == 0) i++;
                if(i<tamanho){
                    memoria[posVazia] = memoria[i];
                    memoria[i] = 0;
                    i = posVazia;
                }
            }
        }
        printf("\nCompactação realizada com sucesso.\n");
    }
    else if(r == 1) printf("\n[!] Erro: Memória já compactada.\n");
    else if(r == 2) printf("\n[!] Erro: Não há nada para compactar.\n");
}

void relatorioMemoria(int memoria[], int tamanho){
    int livre = contarBlocosVazios(memoria, tamanho);
    printf("Total de blocos: %d\n", tamanho);
    printf("Total de blocos vazios: %d\n", livre);
    printf("Total de blocos ocupados: %d\n", tamanho - livre);
    printf("Percentual de ocupação: %.2f%%\n", ((float)(tamanho-livre)/tamanho)*100);
    printf("Maior bloco livre consecutivo: %d\n", maiorBlocoLivre(memoria, tamanho));
    printf("Quantidade de fragmentos: %d\n", contarFragmentos(memoria, tamanho));
}

void relatorioEficiencia(int alocacoes[], int desperdicios[]){
    if(alocacoes[0] + alocacoes[1] + alocacoes[2] == 0){
        printf("Nenhuma alocacao foi realizada.\n");
        return;
    }

    float media[3];

    for(int i = 0; i < 3; i++){
        if(alocacoes[i] > 0)
            media[i] = (float)desperdicios[i] / alocacoes[i];
        else
            media[i] = 0;
    }

    printf("First Fit:\n");
    printf("Alocacoes realizadas: %d\n", alocacoes[0]);
    if(alocacoes[0]!=0){
        printf("Desperdicio total: %d\n", desperdicios[0]);
        printf("Desperdicio medio: %.2f\n\n", media[0]);
    }

    printf("Best Fit:\n");
    printf("Alocacoes realizadas: %d\n", alocacoes[1]);
    if(alocacoes[1]!=0){
        printf("Desperdicio total: %d\n", desperdicios[1]);
        printf("Desperdicio medio: %.2f\n\n", media[1]);
    }

    printf("Worst Fit:\n");
    printf("Alocacoes realizadas: %d\n", alocacoes[2]);
    if(alocacoes[2]!=0){
        printf("Desperdicio total: %d\n", desperdicios[2]);
        printf("Desperdicio medio: %.2f\n\n", media[2]);
    }

    int menor = -1;

    for(int i = 0; i < 3; i++){
        if(alocacoes[i] > 0){
            if(menor == -1 || media[i] < media[menor]){
                menor = i;
            }
        }
    }

    if(menor == 0)
        printf("Menor desperdicio medio: First Fit\n");
    else if(menor == 1)
        printf("Menor desperdicio medio: Best Fit\n");
    else
        printf("Menor desperdicio medio: Worst Fit\n");
}

int maiorBlocoLivre(int memoria[], int tamanho){
    int cont=0;
    int tamMaior=0;
    for(int i=0; i<tamanho; i++){
        if(memoria[i] == 0){
            cont = 0;
            while(i<tamanho && memoria[i] == 0){
                cont++;
                i++;
            }
            if(cont > tamMaior) tamMaior = cont;
        }
    }
    return tamMaior;
}


int contarFragmentos(int memoria[], int tamanho){
    int cont = 0;
    for(int i=0; i<tamanho; i++){
        if(memoria[i]==0){
            cont++;
            while(i<tamanho && memoria[i] == 0){
                i++;
            }
        }
    }
    return cont;
}

int buscarPID(int memoria[], int tamanho, int pid){
    int achou = -1;
    for(int i=0; i<tamanho && achou == -1; i++){
        if(memoria[i] == pid) achou = i;
    }
    return achou;
}

int contarBlocosVazios(int memoria[], int tamanho){
    int cont=0;
    for(int i=0; i < tamanho; i++){
        if(memoria[i] == 0) cont++;
    }
    return cont;
}

int lerInteiroPositivo(){
    int n;
    if(scanf("%d", &n) != 0){
        if(n > 0) return n;
        else return -1;
    }
    else{
        while(getchar()!='\n');
        return -2;
    }
}

int verificarCompactacao(int memoria[], int tamanho){
    for(int i=0; i<tamanho; i++){
        if(memoria[i] == 0){
            for(int k=i; k<tamanho; k++){
                if(memoria[k] != 0) return 0; // Memória não compactada

            }
            return 1; // Memória já compactada
        }
    }
    return 2; // Não há nada a compactar
}
