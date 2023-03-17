//Não esta funcionando

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
} Aluno;

typedef struct {
    Aluno *alunos;
    Aluno *topo;
    int limite;
    int base;
} Pilha;

void CopiaPilha(Aluno *destino, int tam_destino, Aluno *origem, int tam_origem) {
    int i;
    for (i = 0; i < tam_destino && i < tam_origem; i++) {
        destino[i] = origem[i];
    }
}

void Reset(Pilha *pilha){
    pilha->alunos = NULL;
    pilha->topo = NULL;
    pilha->base = 0;
    pilha->limite = 0;
}

void criaPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->limite = 0;
    pilha->alunos = (Aluno*)malloc(sizeof(Aluno));
}


bool empty(Pilha *pilha) {
    return pilha->topo == NULL;
}

bool full(Pilha *pilha) {
    return pilha->topo == pilha->alunos + pilha->limite - 1;
}

bool push(Pilha *pilha, Aluno *dados) {
    if (full(pilha)) {
        pilha->limite++;
        pilha->alunos = (Aluno*)realloc(pilha->alunos, pilha->limite * sizeof(Aluno));
        if (!pilha->alunos) {
            return false;
        }
    }
    pilha->topo++;
    pilha->alunos[pilha->topo] = *dados;
    return true;
}

void pop(Pilha *pilha, Aluno *dados) {
    if (!empty(pilha)) {
        *dados = *(pilha->topo--);
        if (pilha->topo < pilha->alunos + pilha->limite / 4) {
            int novo_limite = pilha->limite / 2;
            Aluno *nova_lista = (Aluno*)malloc(novo_limite * sizeof(Aluno));
            if (!nova_lista) {
                printf("Erro na memoria\n");
                return;
            }
            CopiaPilha(nova_lista, novo_limite, pilha->alunos, pilha->limite);
            free(pilha->alunos);
            pilha->alunos = nova_lista;
            pilha->topo = nova_lista + pilha->limite - 1;
            pilha->limite = novo_limite;
        }
    } else {
        printf("A pilha esta vazia\n");
    }
}

void listarPilha(Pilha *pilha) {
    printf("\nLista: \n");
    Aluno alunos;
    while (!empty(pilha)) {
        pop(pilha, &alunos);
        printf("%s - %i\n", alunos.nome, alunos.idade);
    }
}

int main() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    criaPilha(pilha);

    Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
    strcpy(alunos->nome, "leonardo");
    alunos->idade = 20;

    push(pilha, alunos);
    push(pilha, alunos);
    push(pilha, alunos);
    push(pilha, alunos);
    push(pilha, alunos);
    push(pilha, alunos);

    listarPilha(pilha);

    free(alunos);
    free(pilha->alunos);
    free(pilha);

    return 0;
}
