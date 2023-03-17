#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    
    char nome[30];
    int idade;

} Pessoa;

typedef struct {

    Pessoa pessoa[MAX];
    int topo;
    int base;
    int limite;

} Pilha;

void criaPilha(Pilha *pilha) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

bool vazia(Pilha *pilha) {
    return pilha->topo == 0;
}

bool cheia(Pilha *pilha) {
    return pilha->topo == MAX;
}

bool Push(Pilha *pilha, Pessoa *dado) {
    if (!cheia(pilha)) {
        pilha->pessoa[pilha->topo] = *dado;
        pilha->topo++;
        return true;
    } else {
        printf("Pilha cheia");
        return false;
    }
}

void pop(Pilha *pilha, Pessoa *pessoa) {
    if (!vazia(pilha)) {
        pilha->topo--;
        *pessoa = pilha->pessoa[pilha->topo];
    } else {
        printf("Pilha vazia");
    }
}

void ListarPilha(Pilha *pilha) {
    printf("\nLista: ");
    Pilha novaPilha;
    criaPilha(&novaPilha);
    int i = 0;
    Pessoa pessoa;
    while (!vazia(pilha)) {
        novaPilha.pessoa[i] = pilha->pessoa[pilha->topo-1];
        i++;
        pop(pilha, &pessoa);
        printf("%s - %i\n", pessoa.nome, pessoa.idade);
    }
    int x = i - 1;
    while (x >= 0) {
        Push(pilha, &novaPilha.pessoa[x]);
        x--;
    }
    pilha->topo = i;
}

int main() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    Pessoa *pessoa = (Pessoa*)malloc(sizeof(Pessoa));

    strcpy(pessoa->nome, "leonardo");
    pessoa->idade = 20;

    criaPilha(pilha);
    Push(pilha, pessoa);
    Push(pilha, pessoa);
    Push(pilha, pessoa);
    Push(pilha, pessoa);
    Push(pilha, pessoa);
    Push(pilha, pessoa);
    pop(pilha, pessoa);
    pop(pilha, pessoa);
    pop(pilha, pessoa);
    ListarPilha(pilha);
    printf("\n\n\n");
    ListarPilha(pilha);

    free(pessoa);
    free(pilha);

    return 0;
}