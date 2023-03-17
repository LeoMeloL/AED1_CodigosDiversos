#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct fila {
    struct node *first;
    struct node *last;
}Fila;

typedef struct node {
    int code;
    struct node *next;
}Node;

void push(Fila *f, int c) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->code = c;
    new_node->next = NULL;

    if(f->last != NULL) {
        f->last->next = new_node;
    }
    f->last = new_node;
    if(f->first == NULL) {
        f->first = f->last;
    }
}

BOOL pop(Fila *f, int *c) {
    if(f->first == NULL) {
        return FALSE;
    }

    Node *tmp = f->first;
    *c = tmp->code;
    f->first = tmp->next;
    if(f->first == NULL) {
        f->last = NULL;
    }
    free(tmp);
    return TRUE;
}

void listar(Fila *f) {
    Fila fila_temporaria = {NULL, NULL};
    int code;

    while(pop(f, &code)) {
        printf("%d\n", code);
        push(&fila_temporaria, code);
    }

    while(pop(&fila_temporaria, &code)) {
        push(f, code);
    }
}

int main() {
    Fila f = {NULL, NULL};
    push(&f, 1);
    push(&f, 2);
    push(&f, 3);
    push(&f, 4);
    push(&f, 5);

    printf("Fila original:\n");
    listar(&f);
    listar(&f);

    return 0;
}