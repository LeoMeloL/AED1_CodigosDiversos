//Leia o tamanho do lado de um quadrado e imprima como resultado a sua area.

#include <stdio.h>

int main() {

    float lado, area;

    printf("Digite o lado do quadrado em cm: ");
    scanf("%f", &lado);

    area = lado * lado;

    printf("A area do quadrado eh: %.2fcm", area);

}