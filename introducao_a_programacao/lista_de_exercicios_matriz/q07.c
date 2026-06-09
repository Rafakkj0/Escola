// Escreva um programa que solicite ao usuário o número de linhas e o número de colunas para uma
// matriz retangular A, garantindo, por meio de uma estrutura de validação, que ambos os valores
// fornecidos sejam estritamente maiores que zero e menores que dez. Em seguida, o programa deve
// ler os valores inteiros para preencher essa matriz A. Após a entrada de dados, e de forma
// completamente separada da leitura e da exibição na tela, o programa deve utilizar laços de repetição
// específicos para processar e gerar dois vetores: o vetor SL, onde cada elemento armazena a soma
// dos elementos de uma linha correspondente da matriz, e o vetor SC, onde cada elemento armazena a
// soma dos elementos de uma coluna correspondente. Por fim, o programa deve imprimir os vetores
// SL e SC resultantes. 

#include <stdio.h>

#define TAMANHO_MAX 10

int main(){
    int a[TAMANHO_MAX][TAMANHO_MAX];
    int sl[TAMANHO_MAX] = {0}, sc[TAMANHO_MAX] = {0};
    int tamX, tamY, valor;

    while(1){
        printf("Forneça a quantidade de colunas (X): ");
        scanf("%d", &tamX);
        if(tamX > 0 && tamX < TAMANHO_MAX) break;
        else printf("Forneça um valor positivo menor que 10.\n");
    }
    while(1){
        printf("Forneça a quantidade de linhas (Y): ");
        scanf("%d", &tamY);
        if(tamY>0 && tamY < TAMANHO_MAX) break;
        else printf("Forneça um valor positivo menor que 10.\n");
    }

    printf("Forneça os valores da matriz. \n(X, Y) <- Posição na matriz\n");
    for(int x = 0; x < tamX; x++){
        for(int y = 0; y < tamY; y++){
            printf("(%d, %d): ", x, y);
            scanf("%d", &valor);
            a[y][x] = valor;
        }
    }

    for(int linha = 0; linha < tamY; linha++){
        for(int coluna = 0; coluna < tamX; coluna++){
            sl[linha]+=a[linha][coluna];
        }
    }

    for(int coluna = 0; coluna < tamX; coluna++){
        for(int linha = 0; linha < tamY; linha++){
            sc[coluna]+=a[linha][coluna];
        }
    }

    printf("\nSoma das linhas:\n");
    for(int linha = 0; linha < tamY; linha++){
        printf("%d\t", sl[linha]);
    }
    printf("\nSoma das colunas:\n");
    for(int coluna = 0; coluna < tamX; coluna++){
        printf("%d\t", sc[coluna]);
    }

    printf("\n\nVisualização gráfica:\n");
    for(int l=0; l < tamY; l++){
        for(int c=0; c < tamX; c++){
            printf("%d\t", a[l][c]);
        }
        printf("| %d\n", sl[l]);
    }
    for(int coluna = 0; coluna < tamX; coluna++){
        printf("--------");
    }
    printf("\n");
    for(int coluna = 0; coluna < tamX; coluna++){
        printf("%d\t", sc[coluna]);
    }
    printf("\n\n");
    return 0;
}