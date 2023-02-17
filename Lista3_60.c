#include <stdio.h>

int main(){

    int num , num2, soma = 0,qtd = 0,maiorNum = 0, menorNum = 0, pares = 0, paresQtd = 0;
    float media = 0, paresMedia = 0;

    printf("Digite um numero(0 para sair): ");
    scanf("%d", &num);
    qtd++;

    printf("Digite outro numero(0 para sair): ");
    scanf("%d", &num2);
    qtd++;


    while (num != 0 && num2 != 0) {

        soma += num + num2;
            if (num > num2 || num > maiorNum) {
                maiorNum = num; 
            }
            if (num2 > num || num2 > maiorNum) {
                maiorNum = num2;
            }
            if (num < menorNum || menorNum == 0){
                menorNum = num;
            }
            if (num2 < menorNum || menorNum == 0) {
                menorNum = num2;
            }
            if (num % 2 == 0) {
                pares += num;
                ++paresQtd;
            }
                    if (num2 % 2 == 0) {
                        pares += num2;
                        ++paresQtd;
                    }
        printf("Digite outro numero(0 para sair): ");
        scanf("%d", &num);
        if (num == 0)
            break;
        ++qtd;
        printf("Digite outro numero(0 para sair): ");
        scanf("%d", &num2);
        if (num == 0)
            break;
        ++qtd;

    }

    media = soma / qtd;
    paresMedia = pares / paresQtd;

    printf("\nSoma: %d", soma);
    printf("\nQtd: %d", qtd);
    printf("\nMedia: %.2f", media);
    printf("\nMaior Numero: %d", maiorNum);
    printf("\nMenor Numero: %d", menorNum);
    printf("\nMedia numeros pares: %.2f", paresMedia);
}
