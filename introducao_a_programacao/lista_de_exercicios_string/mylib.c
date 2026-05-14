#include <stdio.h>
#include <string.h>
#include "mylib.h"

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n' && ch!=EOF);
}

void lerString(char str[], int tamanho){
    int tamTexto;
    fgets(str, tamanho, stdin);
    tamTexto = strlen(str);
    if(str[tamTexto - 1] == '\n'){
        str[tamTexto - 1] = '\0';
    }else{
        limpaBuffer();
    }
}