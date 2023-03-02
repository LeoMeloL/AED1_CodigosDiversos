#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int paginas;
    bool emprestado;
} livro;

livro livros[50];

void cadastrarLivro(livro *l){

    int i;
    int emprestado_int;

    for (i = 0; i < 50; ++i){
        if (livros[i].paginas == 0) {
            break;
        }
    }
    if (i == 50) {
        printf("\nNao ha espaco para cadastrar um livro");
        return;
    }

    printf("\nDigite o titulo do livro: ");
    scanf("%s", livros[i].titulo);
    printf("\nDigite o autor do livro: ");
    scanf("%s", livros[i].autor);
    printf("\nDigite o ano de publicacao do livro: ");
    scanf("%d", &livros[i].ano_publicacao);
    printf("\nDigite a qtd de paginas do livro: ");
    scanf("%d", &livros[i].paginas);
    printf("\nO livro está emprestado? (0 para não, 1 para sim): ");
    scanf("%d", &emprestado_int);
    livros[i].emprestado = (emprestado_int == 1);   
}


void ImprimirLivro(livro l) {

    printf("\nTitulo: %s", l.titulo);
    printf("\nAutor: %s", l.autor);
    printf("\nAno de publicacao: %d", l.ano_publicacao);
    printf("\nQtd de paginas: %d", l.paginas);
    if (l.emprestado == 0) {
        printf("\nO livro nao foi emprestado");
    } else {
        printf("\nO livro foi emprestado");
    }
}

void AtualizarLivro(livro *l){

    printf("\nDigite o titulo do livro: ");
    scanf("%s", l->titulo);
    printf("\nDigite o autor do livro: ");
    scanf("%s", l->autor);
    printf("\nDigite o ano de publicacao do livro: ");
    scanf("%d", &l->ano_publicacao);
    printf("\nDigite a qtd de paginas do livro: ");
    scanf("%d", &l->paginas);

}

void emprestarLivro(livro *l) {

    l->emprestado = true;
    printf("\nLivro emprestado");
}

void DevolverLivro(livro *l){

    l->emprestado = false;
    printf("\nLivro devolvido");
}

int menu(){

    int escolha;

    printf("\n1. Cadastrar livro\n");
    printf("2. Consultar informacoes de um livro\n");
    printf("3. Atualizar informacoes de um livro\n");
    printf("4. Emprestar um livro\n");
    printf("5. Devolver um livro\n");
    printf("6. Mostrar todos os livros\n");
    printf("7. Sair\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void ImprimirLivros(){

    for (int i = 0; i < 50; ++i){
        if (livros[i].paginas != 0){
        printf("\n\nLivro %d:", i + 1);
        printf("\nTitulo: %s", livros[i].titulo);
 
        }
    }

}
int main() {

    int imprime;

    for (;;) {
        int escolha = menu();
        switch (escolha) {
            
            case 1:
                cadastrarLivro(livros);
                break;

            case 2:
                printf("Qual livro deseja imprimir ?");
                scanf("%d", &imprime);
                ImprimirLivro(livros[imprime - 1]);
                imprime = 0;
                break;

            case 3:
                printf("Qual livro deseja atualizar ?");
                scanf("%d", &imprime);
                AtualizarLivro(&livros[imprime - 1]);
                imprime = 0;
                break;

            case 4:
                printf("Qual livro foi emprestasdo ? ");
                scanf("%d", &imprime);
                emprestarLivro(&livros[imprime - 1]);
                imprime = 0;
                break;

            case 5:
                printf("Qual livro foi devolvido ?");
                scanf("%d", &imprime);
                DevolverLivro(&livros[imprime - 1]);
                imprime = 0;
                break;

            case 6:
                ImprimirLivros();
                break;

            case 7:
                exit(0);
                break;


        }
    }
}