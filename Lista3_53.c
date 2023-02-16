#include <stdio.h>

int main() {
    int num, i, j, count = 1;

    printf("Digite um numero: ");
    scanf("%d", &num);

    for (i = 0; i <= num; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }

    return 0;
}