#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _queue {
    struct _node *first;
    struct _node *last;
}Queue;

typedef struct _node {
    char name[50];
    struct _node *next;
}Node;

Queue *START();
void PUSH(Queue *pQueue, Node *newNode);
Node *POP(Queue *pQueue);
void CLEAR(Queue *pQueue);
void PRINT(Queue *pQueue);
Node *NEWNODE(char *name);
BOOL EMPTY(Queue *pQueue);

int main() {
    Queue * pQ = START();
    Node * pNode;

PUSH(pQ, NEWNODE("Alice"));
PUSH(pQ, NEWNODE("Bob"));
PUSH(pQ, NEWNODE("Charlie"));
PUSH(pQ, NEWNODE("David"));
PUSH(pQ, NEWNODE("Emma"));
PUSH(pQ, NEWNODE("Frank"));

PRINT(pQ);

pNode = POP(pQ);
free(pNode);
pNode = POP(pQ);
free(pNode);
pNode = POP(pQ);
free(pNode);

printf("\n+---+\n\n");
PRINT(pQ);

PUSH(pQ, NEWNODE("Grace"));
PUSH(pQ, NEWNODE("Henry"));
PUSH(pQ, NEWNODE("Isabella"));

printf("\n+---+\n\n");
PRINT(pQ);

CLEAR(pQ);

return 0;
}

Queue* START() {
    Queue * pQueue = ( Queue * )malloc( sizeof( Queue ) );
    pQueue->first = NULL;
    pQueue->last = NULL;

    return pQueue;
}

void PUSH( Queue * pQueue, Node * newNode ) {
    if ( EMPTY( pQueue ) ) 
        pQueue->first = newNode;
    else
        pQueue->last->next = newNode;
    
    pQueue->last = newNode;
}

Node * POP( Queue * pQueue ) {
    Node * pNode = pQueue->first;

    if ( EMPTY( pQueue ) ) return NULL;

    if ( pQueue->first->next == NULL ) {
        pQueue->first = NULL ;
        pQueue->last = NULL;
        return pNode;
    }

    pQueue->first = pQueue->first->next;

    return pNode;
}

void CLEAR( Queue * pQueue ) {
    Node * tracer = pQueue->first;

    while( pQueue->first ) {
        pQueue->first = pQueue->first->next;
        free( tracer );
        tracer = pQueue->first;
    }

    free( pQueue );
}

void PRINT( Queue * pQueue ) {
    Node * pFirst;
    Node * pNode = NULL;

    pFirst = pQueue->first;

    do {
        pNode = POP( pQueue);
        printf(" %s \n", pNode->name);
        PUSH( pQueue, pNode);
    } while ( pFirst != pQueue->first );
}

Node *NEWNODE(char *name)
{
Node *newNode = (Node *)malloc(sizeof(Node));
strcpy(newNode->name, name);
newNode->next = NULL;
return newNode;
}

BOOL EMPTY( Queue * pQueue ) {
    if ( pQueue->first == NULL ) 
        return TRUE;

    return FALSE;
}
