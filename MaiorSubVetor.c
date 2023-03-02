#include <stdio.h>

int main() {

    int i,j,x, aux;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &i);

    int vetor[i];

    for (j = 0; j < i; ++j) {
        printf("Digite um numero: ");
        scanf("%d", &vetor[j]);
    }

        if (j > 0)
            for (j = 1; j < i; ++j)
                for (x = 0; x < i; ++x)
                    if (vetor[x] > vetor[j]) {
                        aux = vetor[j];
                        vetor[j] = vetor[x];
                        vetor[x] = aux;
                    }

    for (j = 0; j < i; ++j) {
    if (vetor[j + 1] != vetor[j] + 1) {
        printf("Maior subvetor: %d", vetor[j]);
        break;
    }

    }

}