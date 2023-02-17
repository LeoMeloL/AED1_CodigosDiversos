#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = (int *) malloc(5 * sizeof(int));

    if (array == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    printf("Digite 5 numeros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    printf("Os numeros digitados foram: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}