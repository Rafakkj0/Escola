#include <stdio.h>
#include <windows.h>

int numeroArranjos(int, int);
int fat(int);

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n, s;

    printf("Forneça N: ");
    scanf("%d", &n);
    printf("Forneça S: ");
    scanf("%d", &s);

    printf("O resultado é: %d", numeroArranjos(n, s));
    return 0;

}

int fat(int n){
    if(n<0) return -1;
    else{
        int i, fat=1;
        for(i=1; i<=n; i++) fat*=i;
        return fat;
    }
}

int numeroArranjos(int n, int s){
    if(n<0||n<s) return -1;
    else return fat(n)/fat(n-s);
}