#include <string.h>
#include <stdio.h>
#include "leitura.h"

void lerString(char str[], int tamanho){
    int tamString; // tamnho da string (até o '\0')

    fgets(str, tamanho, stdin);

    tamString = strlen(str);

    // verificando se \n pertence a str[]
    if(str[tamString -1] == '\n') str[tamString -1] = '\0';
    else limpaBuffer();
}

void limpaBuffer(){
    int ch;
    do{
        ch = getchar();
    }while(ch != '\n');
}