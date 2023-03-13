#include <stdio.h>
#include <string.h>

int myAtoi(char *s){
    int x = 0;
    int vetor[strlen(s)];
    int num = 0;
    int aux = 1;

    for (int i = 0; i < strlen(s); ++i){

            switch(s[i]){

                case '0':
                vetor[x] = 0;
                ++x;
                break;

                case '1':
                vetor[x] = 1;
                ++x;
                break;

                case '2':
                vetor[x] = 2;
                ++x;
                break;

                case '3':
                vetor[x] = 3;
                ++x;
                break;

                case '4':
                vetor[x] = 4;
                ++x;
                break;

                case '5':
                vetor[x] = 5;
                ++x;
                break;

                case '6':
                vetor[x] = 6;
                ++x;
                break;

                case '7':
                vetor[x] = 7;
                ++x;
                break;

                case '8':
                vetor[x] = 8;
                ++x;
                break;

                case '9':
                vetor[x] = 9;
                ++x;
                break;

                case '-':
                vetor[x] = '-';
                ++x;
                break;

            }
        }

    for (int i = x - 1; i >= 0; --i){
        
        if (vetor[i] != '-') {
        num += aux * vetor[i];
        aux *= 10;
        }
        else {
            num = num * -1;
        }
    }

    return num;
}

int main(){
    char num[100];
    int numero;

    scanf("%s", num);

    numero = myAtoi(num);
    printf("%d ", numero);
}

