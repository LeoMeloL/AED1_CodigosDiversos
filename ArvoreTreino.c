#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Dados{
    int numero;
}Dados;

typedef struct Node{
    Dados data;
    struct Node *pEsq;
    struct Node *pDir;
}Node;

int EhArvoreAVL(Node *pRaiz);
int Altura(Node *pRaiz);
int Fb(Node *pRaiz);
void RSE(Node **pRaiz);
void RSD(Node **pRaiz);
int BalancaEsquerda(Node **pRaiz);
int BalancaDireita(Node **pRaiz);
int Balanceamento(Node **pRaiz);
int Insere(Node **pRaiz, Dados *numero);
int EhArvoreAVL(Node *pRaiz);


int Altura(Node *pRaiz) {
    int iEsq, iDir;

    if (pRaiz == NULL) {
        return 0;
    }

    iEsq = Altura(pRaiz->pEsq);
    iDir = Altura(pRaiz->pDir);

    if (iEsq > iDir) {
        return iEsq + 1;
    } else {
        return iDir + 1;
    }
}

int Fb(Node *pRaiz) {
    if (pRaiz == NULL) {
        return 0;
    }

    return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}

void RSE(Node **pRaiz) {
    Node *pAux;

    pAux = (*pRaiz)->pDir;
    (*pRaiz)->pDir = pAux->pEsq;
    pAux->pEsq = (*pRaiz);
    (*pRaiz) = pAux;
}

void RSD(Node **pRaiz) {
    Node *pAux;

    pAux = (*pRaiz)->pEsq;
    (*pRaiz)->pEsq = pAux->pDir;
    pAux->pDir = (*pRaiz);
    (*pRaiz) = pAux;
}

int BalancaEsquerda(Node **pRaiz){

    int fbe = Fb ((*pRaiz)->pEsq);

    if (fbe > 0){
        RSD(pRaiz);
        return 1;
    }
    else if (fbe < 0){
        RSE( &((*pRaiz)->pEsq));
        RSD(pRaiz);
        return 1;
    }
    return 0;
}

int BalancaDireita(Node **pRaiz){

    int fbd = Fb ((*pRaiz)->pDir);

    if (fbd < 0){
        RSE(pRaiz);
        return 1;
    }
    else if (fbd > 0){
        RSD( &((*pRaiz)->pDir));
        RSE(pRaiz);
        return 1;
    }
    return 0;
}

int Balanceamento(Node **pRaiz){
    int fb = Fb(*pRaiz);

    if (fb > 1){
        return BalancaEsquerda(pRaiz);
    }
    else if (fb < -1){
        return BalancaDireita(pRaiz);
    }
    else {
        return 0;
    }
}

int Insere(Node **pRaiz, Dados *numero){

    if (*pRaiz == NULL){
        *pRaiz = (Node *)malloc(sizeof(Node));
        (*pRaiz)->data = *numero;
        (*pRaiz)->pEsq = NULL;
        (*pRaiz)->pDir = NULL;
        return 1;
    }
    else if ((*pRaiz)->data.numero > numero->numero){
        if (Insere( & (*pRaiz)->pEsq, numero) )
        {
            if (Balanceamento(pRaiz))
                return 0;
            else
                return 1;
        }
    }
    else if ( (*pRaiz)->data.numero < numero->numero) {
        if (Insere( & (*pRaiz)->pDir, numero))
        {
            if (Balanceamento(pRaiz))
                return 0;
            else 
                return 1;
        }
        else
            return 0;
    }
    else
        return 0;
return 0;
}

int EhArvoreAVL(Node *pRaiz){
    int fb;

    if (pRaiz == NULL){
        return 1;
    }

    if (!EhArvoreAVL(pRaiz->pEsq))
        return 0;
    if (!EhArvoreAVL(pRaiz->pDir))
        return 0;

    fb = Fb(pRaiz);
    if ( (fb > 1) || (fb < -1) )
        return 0;
    else
        return 1;
}

int main(){

    srand(time(0));
    Node *pRaiz = NULL;
    Dados numero;
    numero.numero = 10;

    for (int i = 0; i < 1000; ++i){
        numero.numero = rand() % 1000;
        Insere(&pRaiz, &numero);
    }

    if (EhArvoreAVL(pRaiz) == 0){
        printf("Nao eh arvore");
    } else {
        printf("Eh arvore");
    }
}