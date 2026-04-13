/*Em uma elei??o presidencial existem quatro candidatos, sendo:1-Maria Lu?za, 2-Pedro Henrique, 3-Lara Cota e 4-Let?cia Cota. Os votos s?o informados atrav?s de c?digos. Os dados utilizados para a contagem dos votos obedecem ? seguinte codifica??o:
- 1,2,3,4 = voto para os respectivos candidatos;
- 5 = voto nulo;
- 6 = voto em branco;
Elabore um programa que leia o c?digo do candidato em um voto e calcule/escreva.:
? total de votos para cada candidato;
? total de votos nulos;
? total de votos em branco;
? nome do candidato vencedor. Suponha que n?o ocorrer? empate.
Como finalizador do conjunto de votos, tem-se o valor 0.*/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int maria = 0, pedro = 0, lara = 0, leticia = 0, nulo = 0, branco = 0, voto;

    do{
        printf("\n------------------------------------------------------\n");
        printf("1- Maria L?iza    2- Pedro Henrique   3- Lara Cota\n");
        printf("4- Let?cia Cota   5- Nulo             6- Branco\n");
        printf("                  0- Encerrar\n");
        printf("\n-> ");
        scanf("%d",&voto);

        switch (voto){
        case 0:
            break;
        case 1:
            maria++;
            break;
        case 2:
            pedro++;
            break;
        case 3:
            lara++;
            break;
        case 4:
            leticia++;
            break;
        case 5:
            nulo++;
            break;
        case 6:
            branco++;
            break;
        default:
            printf("Voto invalido! Tente novamente\n");
            break;
        }
    }while(voto!=0);

    // Apresentando resultados:
    printf("\n------------------------------------------------------\n");
    if(maria == 0 && pedro == 0 && lara == 0 && leticia == 0){
        printf("Nenhum voto realizado!\n");
    }
    else{
        printf("%d votos para Maria L?iza\n", maria);
        printf("%d votos para Pedro Henrique\n", pedro);
        printf("%d votos para Lara Cota\n", lara);
        printf("%d votos para Let?cia Cota\n", leticia);
        printf("%d votos Nulos\n", nulo);
        printf("%d votos em Branco\n", branco);

        //Verificando o vencedor:
        printf("------------------------------------------------------\n");

        printf("O vencedor ?: ");
        if(maria > pedro && maria > lara && maria > leticia){
            printf("Maria L?iza\n");
        }
        else{
            if(pedro > lara && pedro > leticia){
                printf("Pedro Henrique\n");
            }
            else{
                if(lara > leticia){
                    printf("Lara Cota\n");
                }
                else{
                    printf("Let?cia Cota\n");
                }
            }
        }
        printf("------------------------------------------------------\n");
    }
    return 0;
}