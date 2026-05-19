#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mystring.h"
void converteMaiuscula(char str[]){
    int i;
    for(i=0; str[i];i++)
        str[i]= toupper(str[i]);
    
}
void converteMinuscula(char str[]){
    int i;
    for(i=0; str[i];i++)
        str[i]= tolower(str[i]);
    
}
