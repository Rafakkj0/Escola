#include <stdio.h>
#include <windows.h>

void dobrar(int *n){
    *n *= 2;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int entrada;
    scanf("%d", &entrada);

    dobrar(&entrada);

    printf("\n%d\n", entrada);
    
    return 0;
}