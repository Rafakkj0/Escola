#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleCP(65011);
    SetConsoleOutputCP(65001);

    int n, i;
    float s = 0;
    
    printf("\nForneça o número de termos: ");
    scanf("%d",&n);

    for( i = 1 ; i <= n ; i++){
        s += (float)1 / i;
    }

    printf("\nS = %f\n\n", s);

    return 0;
}