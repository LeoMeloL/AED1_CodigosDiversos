#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* mapeamento[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combina(char* resultado, char** combinacoes, char* digitos, int posicao, int* contador) {
    if (digitos[posicao] == '\0') {
        resultado[posicao] = '\0';
        combinacoes[*contador] = (char*)malloc(strlen(resultado) + 1);
        strcpy(combinacoes[*contador], resultado);
        (*contador)++;
    } else {
        const char* letras = mapeamento[digitos[posicao] - '0'];
        for (int i = 0; letras[i] != '\0'; i++) {
            resultado[posicao] = letras[i];
            combina(resultado, combinacoes, digitos, posicao + 1, contador);
        }
    }
}

char** combinacoes_de_letras(char* digitos, int* tamanho) {
    int contador = 0;
    char resultado[strlen(digitos) + 1];
    char** combinacoes = (char**)malloc(10000 * sizeof(char*));
    combina(resultado, combinacoes, digitos, 0, &contador);
    *tamanho = contador;
    return combinacoes;
}

int main() {
    char digitos[100];
    printf("Digite uma sequencia de digitos de 2 a 9: ");
    scanf("%s", digitos);

    int tamanho;
    char** combinacoes = combinacoes_de_letras(digitos, &tamanho);

    printf("Combinacoes de letras:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", combinacoes[i]);
        free(combinacoes[i]); 
    }
    free(combinacoes);

    return 0;
}
