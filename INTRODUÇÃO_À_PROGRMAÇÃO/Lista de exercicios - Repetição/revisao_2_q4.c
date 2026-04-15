// Um explorador registra criaturas mágicas. Cada criatura possui:
// - Código do tipo (1, 2 ou 3)
// - Nível de poder (1 a 300)
// O programa deve:
// 1. Ler criaturas até que o código seja 0.
// 2. Se o código for inválido, pedir novamente.
// 3. Calcular:
//    - Quantas criaturas de cada tipo
//    - O maior nível registrado
//    - A média dos níveis
//    - Quantas criaturas têm nível maior que 200
#include <stdio.h>
#include <windows.h>

#define MIN_FORTE 200

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int codigo, poder, qtd1 = 0, qtd2 = 0, qtd3 = 0, maiorPoder, somaPoder = 0, qtdFortes = 0;

    printf("----------- POKÉDEX -----------\n");
    printf("    Para encerrar digite 0.    \n");
    while(1){
        printf("\n- Qual o tipo do pokémon?\n");
        printf("1 - Fogo | 2 - Água | 3- Planta\n");
        printf("\n-> ");
        scanf("%d", &codigo);
        if(codigo == 0) break;
        if(codigo < 1 || codigo > 3){
            printf("\nValor invalido, tente novamente.\n");
            continue;
        }

        do{
            printf("\n- Qual o nível de poder\n  do pokémon\n");
            printf("\n-> ");
            scanf("%d", &poder);
            if(poder < 1 || poder > 300) printf("\nValor invalido, tente novamente.\n");
        }while(poder < 1 || poder > 300);

        if(qtd1 == 0 && qtd2 == 0 && qtd3 == 0 || poder > maiorPoder) maiorPoder = poder;

        switch(codigo){
            case 1:
                qtd1++;
                break;
            case 2:
                qtd2++;
                break;
            case 3:
                qtd3++;
                break;
        }

        somaPoder+=poder;

        if(poder >= MIN_FORTE) qtdFortes;
    }
    if(qtd1 != 0 || qtd2 != 0 || qtd3 != 0){
        printf("\nQuantidade de pokémons do tipo fogo: %d\n", qtd1);
        printf("Quantidade de pokémons do tipo água: %d\n", qtd2);
        printf("Quantidade de pokémons do tipo planta: %d\n", qtd3);
        printf("Maio nível de poder registrado: %d\n", maiorPoder);
        printf("Média dos níveis de poder: %.2f\n", (float)somaPoder / (qtd1 + qtd2 + qtd3));
        printf("Quantidade de pókemons fortes: %d\n\n", qtdFortes);
    }
    return 0;
}