#include <stdio.h>

int main(){
    int num;


    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num % 11 != 0 && num % 13 != 0 && num % 17 != 0) {
     num++;
    }

     printf("O multiplo mais proximo eh: %d", num);
}