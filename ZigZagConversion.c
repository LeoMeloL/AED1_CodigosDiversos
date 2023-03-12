//https://leetcode.com/problems/zigzag-conversion/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char * s, int numRows);

char *convert(char * s, int numRows){

char matriz[20][20];
int x = 1;
int j = 0;
numRows -= 1;
char *palavra = malloc(strlen(s) + 1);

    for (int i = 0; i < 20; ++i){
        for (int k = 0; k < 20; ++k){
            matriz[i][k] = ' ';
        }
    }

    matriz[0][0] = s[0];

    for (int i = 1; x < strlen(s); ++i){
        matriz[i][j] = s[x];
        ++x;
            if (i == numRows) {
                while (i != 0){
                    ++j;
                    --i;
                    matriz[i][j] = s[x];
                    ++x;
                }
            }
    }

//          for(int i = 0; i < numRows + 1; ++i) {
//            printf("\n");
//           for (int k = 0; k < 7; ++k){
//            printf("%c ", matriz[i][k]);
//        }
 //   }

 int y = 0;
    for (int i = 0; i < numRows + 1; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (matriz[i][j] != ' ') {
                palavra[y] = matriz[i][j];
                ++y;
            }
        }
    }

    palavra[y] = '\0';

    return palavra;
}

int main(){

    char string[30];
    int rows;

    printf("Digite a string: ");
    scanf("%s", string);

    printf("Digite as rows: ");
    scanf("%d", &rows);

    char *palavra = convert(string, rows);
    printf("\n\n");

    for (int i = 0; i < 20; ++i){
        printf("%c", palavra[i]);
    }

}



