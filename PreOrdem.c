#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

void printPreorder(Node* node) {
    if (node == NULL) {
        return;
    }
    
    printf("%d ", node->value);
    printPreorder(node->left);
    printPreorder(node->right);
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = (Node*) malloc(sizeof(Node));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (value < (*root)->value) {
            insert(&((*root)->left), value);
        } else {
            insert(&((*root)->right), value);
        }
    }
}

int main() {
    Node* root = NULL;
    
    // Insere alguns valores na árvore binária
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);
    insert(&root, 7);
    
    // Imprime a árvore em pré-ordem
    printf("Árvore em pré-ordem: ");
    printPreorder(root);
    printf("\n");
    
    return 0;
}