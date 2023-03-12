#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p){

    for (int i = 0; i < strlen(s); ++i){
        if (p[i] == '.'){
            p[i] = s[i];
                if (p[i + 1] == '*') {
                    p[i + 1] = s[i + 1];
                    ++i;
                }
        }
        if (p[i] == '*'){
            p[i] = p[i - 1];
        }
    }

    if (strcmp(p,s) == 0){
        return true;
    } else {
        return false;
    }
}

int main(){

    char p[20], s[20];
    bool x;

    printf("Digite a string S: ");
    scanf("%s", s);
    printf("Digite a string P: ");
    scanf("%s", p);

    x = isMatch(s,p);

    if (x == true){
        printf("true");
    } else {
        printf("false");
    }

    
}