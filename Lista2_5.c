/*Faca um programa que receba um numero inteiro e verifique se este numero e par ou
impar*/

#include <stdio.h>

int main() {

    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num % 2 == 0)
     printf("O numero eh par");

     else {
        printf("O numero eh impar");
     }

}