#include <stdio.h>

void imprimir_array(int *array, int tamanho) {
    int *ponteiro = array;
    int *fim = array + tamanho;

    while (ponteiro < fim) {
        printf("%d ", *ponteiro);
        ponteiro++;
    }
    printf("\n");
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    imprimir_array(array, 5);
    return 0;
}