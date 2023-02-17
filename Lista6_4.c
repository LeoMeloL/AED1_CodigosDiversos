#include <stdio.h>


struct Aluno {
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
};

int main(){
    struct Aluno alunos[5];
    float maiorNota1 = 0, media = 0, maiorMediaGeral = 0, menorMediaGeral = 0;
    int maiorNota1Aluno, melhorAluno, piorAluno, i;
    
    for (i = 0; i < 5; ++i) {

    printf("Digite o nome do aluno: ");
    scanf("%s", alunos[i].nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos[i].matricula);
    printf("Digite a nota da primeira prova: ");
    scanf("%f", &alunos[i].nota1);
    printf("Digite a nota da segunda prova: ");
    scanf("%f", &alunos[i].nota2);
    printf("Digite a nota da terceira prova: ");
    scanf("%f", &alunos[i].nota3);

        if (alunos[i].nota1 > maiorNota1) {
            maiorNota1 = alunos[i].nota1;
            maiorNota1Aluno = i;
        }

media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;
        if (media < 6.0) {
            printf("Aluno %s reprovado na disciplina.\n", alunos[i].nome);
        } else {
            printf("Aluno %s aprovado na disciplina.\n", alunos[i].nome);
        }

    if (media > maiorMediaGeral) {
        maiorMediaGeral = media;
        melhorAluno = i;
    }
    if (media < menorMediaGeral || menorMediaGeral == 0) {
        menorMediaGeral = media;
        piorAluno = i;
    }
    }

    printf("\nAluno com maior nota da primeira prova: ");
    printf("\nNome: %s\nMatricula: %d\nNota1: %.1f\nNota2: %.1f\nNota3: %.1f\n", alunos[maiorNota1Aluno].nome, alunos[maiorNota1Aluno].matricula, alunos[maiorNota1Aluno].nota1, alunos[maiorNota1Aluno].nota2, alunos[maiorNota1Aluno].nota3);
    printf("------------------------------------------------------------------");
    printf("\nAluno com maior media geral: ");
    printf("\nNome: %s\nMatricula: %d\nNota1: %.1f\nNota2: %.1f\nNota3: %.1f\n", alunos[melhorAluno].nome, alunos[melhorAluno].matricula, alunos[melhorAluno].nota1, alunos[melhorAluno].nota2, alunos[melhorAluno].nota3);
    printf("------------------------------------------------------------------");
    printf("\nAluno com menor media geral: ");
    printf("\nNome: %s\nMatricula: %d\nNota1: %.1f\nNota2: %.1f\nNota3: %.1f\n", alunos[piorAluno].nome, alunos[piorAluno].matricula, alunos[piorAluno].nota1, alunos[piorAluno].nota2, alunos[piorAluno].nota3);


}

