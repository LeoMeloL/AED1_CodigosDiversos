/* Leia um valor de comprimento em polegadas e apresente-o convertido em centimetros.
A formula de conversao e: C = P ∗ 2, 54, sendo C o comprimento em centimetros e P o
comprimento em polegadas. */

#include <stdio.h>

int main() {

    float c, pol;

    printf("Digite as polegadas: ");
    scanf("%f", &pol);

    c = pol * 2.54;

    printf("%.3f polegadas em cm eh: %.2fcm", pol, c);
}