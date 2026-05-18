// Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses caractere na string

#include <stdio.h>
#include "mylib.h"

#define MAX_CARACTER 100

void removeCaractere(char str[], char c){
    int i, k;
    for(i=0; str[i] ;i++){
        if(str[i] == c){
            for(k=i; str[k]; k++){
                str[k] = str[k+1];
            }
            i--;
        }
    }
}

int main(){
    char txt[MAX_CARACTER], c;

    printf("\n----- Removedor de caracteres -----\n");
    printf("Escreva o texto que deseja remover um caractere:\n\n");
    lerString(txt, MAX_CARACTER);

    printf("\nQual caractere deseja remover: ");
    scanf("%c", &c);

    removeCaractere(txt, c);

    printf("Texto com os caracteres '%c' removidos:\n%s\n\n", c, txt);
    

    return 0;
}
