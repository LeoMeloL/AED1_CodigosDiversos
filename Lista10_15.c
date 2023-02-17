#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int numero;

    do {
        printf("Digite um numero (negativo para sair): ");
        scanf("%d", &numero);

        if (numero >= 0) {
            tamanho++;
            vetor = realloc(vetor, tamanho * sizeof(int));
            vetor[tamanho - 1] = numero;
        }

    } while (numero >= 0);

    printf("\nVetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}