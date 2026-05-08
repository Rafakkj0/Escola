// Leia 50 números e mostre o segundo maior valor.

#include <stdio.h>
#include "minhaBiblioteca.h"

#define TAMANHO 50

int main(){
    int priMaior, segMaior, v[TAMANHO];
    
    printf("\n\nFoneça %d valores para verificar qual o segudo maior:\n", TAMANHO);
    lerVetorCont(v, TAMANHO);

    if(v[0] > v[1]){
        priMaior = v[0];
        segMaior = v[1];
    }
    else{
        priMaior = v[1];
        segMaior = v[0];
    }

    for(int i=2; i < TAMANHO; i++){
        if(v[i] > priMaior){
            segMaior = priMaior;
            priMaior = v[i];
        }
        else{
            if(v[i] > segMaior){
                segMaior = v[i];
            }
        }
    }

    printf("\nO segundo maior valor desta seguência é %d.\n\n", segMaior);

    return 0;
}