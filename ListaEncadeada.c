#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
} Dados;

typedef struct sNodo {
   Dados info;
   struct sNodo *pNext;
} sNodo;

typedef struct {
    sNodo *pFirst;
} Sentinela;


void remover(Sentinela *lista, char nome[]) {
    sNodo *nodoAtual = lista->pFirst;
    sNodo *nodoAnterior = NULL;

    while (nodoAtual != NULL && strcmp(nodoAtual->info.nome, nome) != 0) {
        nodoAnterior = nodoAtual;
        nodoAtual = nodoAtual->pNext;
    }

    if (nodoAtual == NULL) {
        printf("Pessoa nao encontrada.\n");
        return;
    }

    if (nodoAnterior == NULL) {
        lista->pFirst = nodoAtual->pNext;
    } else {
        nodoAnterior->pNext = nodoAtual->pNext;
    }

    free(nodoAtual);
}


void adicionar(Sentinela *lista, Dados dados) {
    sNodo *novoNodo = (sNodo*) malloc(sizeof(sNodo));
    novoNodo->info.idade = dados.idade;
    strcpy(novoNodo->info.nome, dados.nome);
    novoNodo->pNext = NULL;

    if (lista->pFirst == NULL) {
        lista->pFirst = novoNodo;
        return;
    }

    sNodo *nodoAtual = lista->pFirst;
    sNodo *nodoAnterior = NULL;
    while (nodoAtual != NULL && strcmp(nodoAtual->info.nome, novoNodo->info.nome) < 0) {
        nodoAnterior = nodoAtual;
        nodoAtual = nodoAtual->pNext;
    }
    if (nodoAnterior == NULL) {
        novoNodo->pNext = lista->pFirst;
        lista->pFirst = novoNodo;
    } else {
        novoNodo->pNext = nodoAtual;
        nodoAnterior->pNext = novoNodo;
    }
}

void listar(Sentinela lista) {
    sNodo *nodoAtual = lista.pFirst;
    while (nodoAtual != NULL) {
        printf("Nome: %s, Idade: %d\n", nodoAtual->info.nome, nodoAtual->info.idade);
        nodoAtual = nodoAtual->pNext;
    }
}

int main() {
    Sentinela lista = {NULL};
    Dados *dados = NULL;
    int i = 0;
    do {
        dados = (Dados*) realloc(dados, (i+1) * sizeof(Dados));
        if (dados == NULL) {
            printf("Erro de alocacao de memoria.\n");
            return 1;
        }
        printf("Digite um nome (null para sair): ");
        scanf("%s", dados[i].nome);
        if (strcmp(dados[i].nome, "null") == 0) {
            break;
        }
        printf("Idade: ");
        scanf("%d", &dados[i].idade);
        adicionar(&lista, dados[i]);
        i++;
    } while (1);

    listar(lista);
    free(dados);
    return 0;
}
