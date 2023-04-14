#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

bool isIdentical(Node* node1, Node* node2) {
    if (node1 == NULL && node2 == NULL) {
        return true;
    }
    
    if (node1 == NULL || node2 == NULL) {
        return false;
    }
    
    if (node1->value != node2->value) {
        return false;
    }
    
    return isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if (subRoot == NULL) {
        return true;
    }
    
    if (root == NULL) {
        return false;
    }
    
    if (root->value == subRoot->value && isIdentical(root, subRoot)) {
        return true;
    }
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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
    // Lê os valores da árvore
    Node* root = NULL;
    int value;
    printf("Digite os valores da árvore um por um (digite -1 para encerrar):\n");
    do {
        scanf("%d", &value);
        if (value != -1) {
            insert(&root, value);
        }
    } while (value != -1);
    
    // Lê os valores da subárvore
    Node* subRoot = NULL;
    printf("Digite os valores da subárvore um por um (digite -1 para encerrar):\n");
    do {
        scanf("%d", &value);
        if (value != -1) {
            insert(&subRoot, value);
        }
    } while (value != -1);
    
    // Verifica se a subárvore está contida na árvore
    if (isSubtree(root, subRoot)) {
        printf("A subárvore está contida na árvore.\n");
    } else {
        printf("A subárvore não está contida na árvore.\n");
    }
    
    return 0;
}