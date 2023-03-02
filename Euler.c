#include <stdio.h>
#include <math.h>

double fatorial(int n);

double fatorial(int n){

    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main(){

    int n = 1, x = 0;
    long double e = 0;
    printf("Digite o numero de termos da serie: ");
    scanf("%d", &x);

    e = 1;
    double fat;
    while (n < x){
        fat = fatorial(n);
        e += 1/fat;
        ++n;
    }

    printf("Euler: %.20Lf", e);

    return 0;
}