#include <stdio.h>
#include <windows.h>

void trocar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int x, y;
    scanf("%d %d", &x, &y);

    trocar(&x, &y);
    printf("%d  %d", x, y);

    return 0;
}