#include <string.h>
#include <stdio.h>
#include "leitura.h"

int limparBuffer(){
    int c, retorno = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        retorno = 1;
    }
    return retorno;
}

int lerString(char texto[], int tamanho){
    int t;
    
    if (fgets(texto, tamanho, stdin) == NULL) return 0; // Falha na leitura (ex: fim do arquivo/EOF)
     
    t = strlen(texto);
     
    if (t == 0) return 0; // se o usúario não digitar nada
        
    if (texto[t - 1] == '\n') texto[t - 1] = '\0';
    else limparBuffer(); 
    
    return 1;     
}

int lerInt(int *valor) {
    int erro = 0;
    
    if (scanf("%d", valor) == 1) {
        
        erro = limparBuffer();
        return !erro;
    }
    
    limparBuffer();
    return 0;
}
int lerFloat(float *valor) {
   int erro = 0;
   if (scanf("%f", valor) == 1) {
        erro = limparBuffer();
        return !erro ;
    }
    
    limparBuffer();
    return 0;
}
int lerDouble(double *valor) {
    int erro = 0;
    if (scanf("%lf", valor) == 1) {
        erro = limparBuffer();
        return !erro;
    }
    
    limparBuffer();
    return 0;
    
}