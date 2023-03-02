#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int linhas, colunas;
    int soma = 0;

    printf("Digite as colunas da matriz: ");
    scanf("%d", &colunas);
    printf("Digite as linhas da matriz: ");
    scanf("%d", &linhas);

    int **matriz = (int **)malloc(colunas * sizeof(int *));
        for (int i = 0; i < colunas; ++i){
            matriz[i] = (int *)malloc(linhas * sizeof(int));
                for (int j = 0; j < linhas; ++j){
                    matriz[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < colunas; ++i){
        printf("\n");
        for(int j = 0; j < linhas; ++j){
            printf("%d ", matriz[i][j]);
            if (j == i) {
                soma += matriz[i][j];
            }
        }
    }

    printf("\nSoma da diagonal principal: %d", soma);
    return 0;
}