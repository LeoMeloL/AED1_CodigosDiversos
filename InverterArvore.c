#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* invertTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->value);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Constrói a árvore de exemplo
    Node* root = (Node*) malloc(sizeof(Node));
    root->value = 4;
    root->left = (Node*) malloc(sizeof(Node));
    root->left->value = 2;
    root->left->left = (Node*) malloc(sizeof(Node));
    root->left->left->value = 1;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (Node*) malloc(sizeof(Node));
    root->left->right->value = 3;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (Node*) malloc(sizeof(Node));
    root->right->value = 7;
    root->right->left = (Node*) malloc(sizeof(Node));
    root->right->left->value = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (Node*) malloc(sizeof(Node));
    root->right->right->value = 9;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    
    printf("Árvore original: ");
    printTree(root);
    printf("\n");
    
    root = invertTree(root);
    
    printf("Árvore invertida: ");
    printTree(root);
    printf("\n");
    
    return 0;
}