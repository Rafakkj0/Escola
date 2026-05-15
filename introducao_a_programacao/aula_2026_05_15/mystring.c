#include <ctype.h>
#include "leitura.h"

void convertMaiuscula(char str[]){
    for(int i=0; str[i]; i++){   //   0 e nulo sempre é falso, não é necessario fazer str[i] != '\0', pois quando chegar lá str[i] será falso por se só.
        str[i]=toupper(str[i]);
    }
}

void convertMinuscula(char str[]){
    for(int i=0; str[i]; i++){
        str[i]=tolower(str[i]);
    }
}
