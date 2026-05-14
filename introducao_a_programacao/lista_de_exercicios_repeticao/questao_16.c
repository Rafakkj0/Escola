/*Escrever um programa que leia um número n que indica quantos valores devem ser lidos. Para cada número lido, mostre uma tabela contendo o valor lido e o fatorial deste valor.*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int numVezes, n, fat, i;

    printf("\nQuantos números você quer forneçer? ");
    scanf("%d",&numVezes);
    if(numVezes > 0){
        for(  ; numVezes != 0 ; numVezes-- ){
            fat=1;
            printf("Fatorial de: ");
            scanf("%d",&n);

            if(n>=0){
                for( i = 1 ; i <= n ; i++ ){
                    fat = fat * i;
                }
                printf("%d! = %d\n", n, fat);
            }
            else{
                printf("O número deve ser maior ou igual a 0.");
                numVezes++;
            }
        }
    }
    else printf("Forneça uma quantidade maior que 0");
    return 0;
}