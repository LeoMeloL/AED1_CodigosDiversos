#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _queue {
    struct _node *first;
    struct _node *last;
}Queue;

typedef struct _node {
    int code;
    struct _node *next;
}Node;

Queue *START();
void PUSH( Queue * pQueue, Node * newNode );
Node * POP( Queue * pQueue );
void CLEAR( Queue * pQueue );
void PRINT( Queue * pQueue );
Node * NEWNODE( int code );
BOOL EMPTY( Queue * pQueue);

int main() {
    Queue * pQ = START();
    Node * pNode;

    PUSH( pQ, NEWNODE(1) );
    PUSH( pQ, NEWNODE(2) );
    PUSH( pQ, NEWNODE(3) );
    PUSH( pQ, NEWNODE(4) );
    PUSH( pQ, NEWNODE(5) );
    PUSH( pQ, NEWNODE(6) );

    PRINT( pQ );
    
    pNode = POP( pQ );
    free( pNode );
    pNode = POP( pQ );
    free( pNode );
    pNode = POP( pQ );
    free( pNode );

    printf("\n+---+\n\n");
    PRINT( pQ );

    PUSH( pQ, NEWNODE(1) );
    PUSH( pQ, NEWNODE(2) );
    PUSH( pQ, NEWNODE(3) );

    printf("\n+---+\n\n");
    PRINT( pQ );

    CLEAR( pQ );

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
        printf(" %d \n", pNode->code);
        PUSH( pQueue, pNode);
    } while ( pFirst != pQueue->first );
}

Node *NEWNODE( int code ) {
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    newNode->code = code;
    newNode->next = NULL;

    return newNode;
}

BOOL EMPTY( Queue * pQueue ) {
    if ( pQueue->first == NULL ) 
        return TRUE;

    return FALSE;
}