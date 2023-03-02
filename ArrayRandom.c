#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));

    int x, soma = 0;
    printf("Digite o tamanho do array: ");
    scanf("%d", &x);

    int array[x];

    for (int i = 0; i < x; ++i) {
        array[i] = rand() % 50;
            if (array[i] % 3 == 0)
                soma += array[i];
    }
    printf("O array eh: ");
    for (int i = 0; i < x; ++i)
    printf("%d ", array[i]);
    
    printf("A soma dos divisiveis por 3 eh: %d", soma);
}
