#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    int inicio = 0, fim;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    fim = strlen(palavra) - 1;

    while (fim > inicio) {
        if (palavra[inicio++] != palavra[fim--]) {
            printf("A palavra nao eh um palindromo\n");
            return 0;
        }
    }

    printf("A palavra eh um palindromo\n");
    return 0;
}





