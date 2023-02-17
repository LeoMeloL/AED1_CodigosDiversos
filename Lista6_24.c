#include <stdio.h>
#include <string.h>

struct Endereco{
    char rua[100];
    int numero;
    char complemento[100];
    char bairro[100];
    char cep[100];
    char cidade[100];
    char estado[100];
    char pais[100];
};

struct Telefone{
    int ddd;
    int numero;
};

struct Aniversario{
    int dia;
    int mes;
    int ano;
};


struct Agenda{
    char nome[100];
    char email[100];
    struct Endereco endereco;
    struct Telefone telefone;
    struct Aniversario dataAniversario;
    char observacao[100];
};

struct Agenda agenda[100];

void buscaNome();
void buscaMes();
void buscaDiaMes();
void insereNome();
void retiraPessoa();
void imprimeTudo();
void imprimeRedux();
int menu();

void buscaNome(){

    char nome[100];
    int i;
    printf("Digite o nome a ser encontrado: ");
    scanf("%s", nome);

        for (i = 0; i < 100; ++i)
            if (strcmp(nome, agenda[i].nome) == 0) {
                printf("Nome: %s\nEmail: %s\nEndereco: %s %i %s %s %s %s %s\nTelefone: (%i)%i\nDataAniversario: %d/%d/%d", agenda[i].nome, agenda[i].email, agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.bairro, agenda[i].endereco.cep, agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais, agenda[i].telefone.ddd, agenda[i].telefone.numero, agenda[i].dataAniversario.dia, agenda[i].dataAniversario.mes, agenda[i].dataAniversario.ano);
                printf("\n\n");
            }
                    else {
                        printf("Nome nao encontrado: ");
                    }

}

void buscaMes(){

    int mes,i;
    printf("\nDigite o mes: ");
    scanf("%d", &mes);

        for (i = 0; i < 100; ++i)
            if (agenda[i].dataAniversario.mes == mes) {
                printf("Nome: %s\nEmail: %s\nEndereco: %s %i %s %s %s %s %s\nTelefone: (%i)%i\nDataAniversario: %i/%i/%i",agenda[i].nome, agenda[i].email, agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.bairro, agenda[i].endereco.cep,agenda[i].endereco.cidade,agenda[i].endereco.estado,agenda[i].endereco.pais,agenda[i].telefone.ddd,agenda[i].telefone.numero,agenda[i].dataAniversario.dia,agenda[i].dataAniversario.mes,agenda[i].dataAniversario.ano);
                printf("\n\n");
            }
                else{
                    printf("Nenhum aniversariante nesse mes");
                }


}

void buscaDiaMes(){
    int mes, dia, i, encontrou = 0;

    printf("\nDigite o mes: ");
    scanf("%d", &mes);
    printf("\nDigite o dia: ");
    scanf("%d", &dia);

        for (i = 0; i < 100; ++i) {
            if (agenda[i].dataAniversario.mes == mes && agenda[i].dataAniversario.dia == dia) {
                printf("Nome: %s\nEmail: %s\nEndereco: %s %i %s %s %s %s %s\nTelefone: (%i)%i\nDataAniversario: %i/%i/%i",agenda[i].nome,agenda[i].email,agenda[i].endereco.rua,agenda[i].endereco.numero,agenda[i].endereco.bairro,agenda[i].endereco.cep,agenda[i].endereco.cidade,agenda[i].endereco.estado,agenda[i].endereco.pais,agenda[i].telefone.ddd,agenda[i].telefone.numero,agenda[i].dataAniversario.dia,agenda[i].dataAniversario.mes,agenda[i].dataAniversario.ano);
                encontrou = 1;
            }
        }
            if (!encontrou)
                printf("\nNenhum aniversariante nessa data\n");
        
     }



void insereNome() {
    char escolha[10], observacao[10];
    int i;
    static int contador = 0;

    if (contador == 100) {
        printf("Agenda cheia!\n");
        return;
    }

    for (i = 0; i < 100; ++i) {
        if (agenda[i].nome[0] == '\0') {
            printf("\nDigite o nome: ");
            scanf("%s", agenda[i].nome);
            printf("\nDigite o email: ");
            scanf("%s", agenda[i].email);
            printf("\nDigite a rua: ");
            scanf("%s", agenda[i].endereco.rua);
            printf("\nDigite o numero da casa: ");
            scanf("%d", &agenda[i].endereco.numero);
            printf("\nDeseja informar um complemento ?[S,N] ");
            scanf("%s", escolha);
            if (escolha[0] == 's' || escolha[0] == 'S') {
                printf("\nDigite o complemento: ");
                scanf("%s", agenda[i].endereco.complemento);
            }
            printf("\nDigite o bairro: ");
            scanf("%s", agenda[i].endereco.bairro);
            printf("\nDigite o CEP: ");
            scanf("%s", agenda[i].endereco.cep);
            printf("\nDigite a cidade: ");
            scanf("%s", agenda[i].endereco.cidade);
            printf("\nDigite o estado: ");
            scanf("%s", agenda[i].endereco.estado);
            printf("\nDigite o pais: ");
            scanf("%s", agenda[i].endereco.pais);
            printf("\nDigite o DDD: ");
            scanf("%d", &agenda[i].telefone.ddd);
            printf("\nDigite o numero do telefone: ");
            scanf("%d", &agenda[i].telefone.numero);
            printf("\nDigite o dia de aniversario: ");
            scanf("%d", &agenda[i].dataAniversario.dia);
            printf("\nDigite o mes de aniversario: ");
            scanf("%d", &agenda[i].dataAniversario.mes);
            printf("\nDigite o ano de aniversario: ");
            scanf("%d", &agenda[i].dataAniversario.ano);
            printf("Voce deseja informar alguma observacao? ");
            scanf("%s", observacao);
                if (observacao[0] == 's' || observacao[0] == 'S') {
                    printf("\nDigite a observacao: ");
                    scanf("%s", agenda[i].observacao);
                }

            contador++;
            break;
        }
    }
}

void retiraPessoa(){

    char nome[100];
    int i;

    printf("\nDigite o nome a ser retirado: ");
    scanf("%s", nome);

    for (i = 0; i < 100; ++i)
        if (strcmp(agenda[i].nome, nome) == 0) {
            agenda[i] = agenda[i + 1];
            printf("\nNome removido");
        }

}

void imprimeTudo(){

    int i;
    for (i = 0; agenda[i].nome[0] != '\0'; ++i) {
        printf("\nNome: %s", agenda[i].nome);
        printf("\nEmail: %s", agenda[i].email);
        printf("\nRua: %s, %d", agenda[i].endereco.rua, agenda[i].endereco.numero);
        printf("\nBairro: %s", agenda[i].endereco.bairro);
        printf("\nCEP: %s", agenda[i].endereco.cep);
        printf("\nCidade: %s", agenda[i].endereco.cidade);
        printf("\nEstado: %s", agenda[i].endereco.estado);
        printf("\nPais: %s", agenda[i].endereco.pais);
        printf("\nTelefone: (%d)%d", agenda[i].telefone.ddd, agenda[i].telefone.numero);
        printf("\nData de Aniversario: %d/%d/%d", agenda[i].dataAniversario.dia, agenda[i].dataAniversario.mes, agenda[i].dataAniversario.ano);
    }
}

void imprimeRedux(){

    int i;
    
    for (i = 0; agenda[i].nome[0] != '\0'; ++i) {
    printf("\nNome: %s", agenda[i].nome);
    printf("\nTelefone: (%d)%d", agenda[i].telefone.ddd, agenda[i].telefone.numero);
    printf("\nEmail: %s", agenda[i].email);
    }
}

int menu(){

    int escolha;

    printf("\n1. Insere Pessoa");
    printf("\n2. Retira Pessoa");
    printf("\n3. Busca Nome");
    printf("\n4. Busca mes");
    printf("\n5. Busca data");
    printf("\n6. Imprime Tudo");
    printf("\n7. Imprime Reduzido");
    printf("\n8. Sair"); 
    printf("\nQual sua escolha: ");
    scanf("%d", &escolha);

return escolha;
}

int main(){

    int escolha;
    for(;;) {
    escolha = menu();
    switch(escolha){
        case 1:
        insereNome();
        break;

        case 2:
        retiraPessoa();
        break;

        case 3:
        buscaNome();
        break;

        case 4:
        buscaMes();
        break;

        case 5:
        buscaDiaMes();
        break;

        case 6:
        imprimeTudo();
        break;

        case 7:
        imprimeRedux();
        break;

        }
    }
}