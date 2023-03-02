#include <stdio.h>
#include <stdlib.h>

int main(){
    int coluna,linha, caminho = 0;

    printf("Digite as colunas: ");
    scanf("%d", &coluna);
    printf("Digite as linhas: ");
    scanf("%d", &linha);

    int **matriz =(int **) malloc (coluna * sizeof(int *));

    for (int i = 0; i < coluna; ++i) {
        matriz[i] = (int *)malloc(linha * sizeof(int));
        for (int j = 0; j < linha; ++j){
            matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < coluna; ++i) {
        for (int j = 0; j < linha; ++j){
            printf("Digite o valor da matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Menor caminho: \n\n");

    int i = 0, j = 0;
    while (i < coluna - 1 || j < linha - 1) {
        if (i == coluna - 1) {
            ++j;
            printf("(%d,%d) = %d\n", i, j, matriz[i][j]);
            caminho += matriz[i][j];
        } else if (j == linha - 1) {
            ++i;
            printf("(%d,%d) = %d\n", i, j, matriz[i][j]);
            caminho += matriz[i][j];
        } else if (matriz[i + 1][j] < matriz[i][j + 1]) {
            ++i;
            caminho += matriz[i][j];
            printf("(%d,%d) = %d\n", i, j, matriz[i][j]);
        } else {
            ++j;
            caminho += matriz[i][j];
            printf("(%d,%d) = %d\n", i, j, matriz[i][j]);
        }
    }

    printf("Custo %d", caminho);

    for (int i = 0; i < coluna; ++i){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}