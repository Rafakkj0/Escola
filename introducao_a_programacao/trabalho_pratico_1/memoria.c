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

}

void relatorioEficiencia(int alocacoes[], int desperdicios[]){

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