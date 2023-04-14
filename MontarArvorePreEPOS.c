#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* buildTree(int* preorder, int* inorder, int* postorder, int length) {
    if (length == 0) {
        return NULL;
    }
    
    Node* root = (Node*) malloc(sizeof(Node));
    root->value = preorder[0];
    root->left = NULL;
    root->right = NULL;
    
    if (length == 1) {
        return root;
    }
    
    int i;
    for (i = 0; i < length; i++) {
        if (inorder[i] == root->value) {
            break;
        }
    }
    
    int leftLength = i;
    int rightLength = length - i - 1;
    
    root->left = buildTree(preorder + 1, inorder, postorder, leftLength);
    root->right = buildTree(preorder + 1 + leftLength, inorder + leftLength + 1, postorder + leftLength, rightLength);
    
    return root;
}

void printInorder(Node* node) {
    if (node == NULL) {
        return;
    }
    
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

int main() {
    int preorder[] = {4, 2, 1, 3, 6, 5, 7};
    int inorder[] = {1, 2, 3, 4, 5, 6, 7};
    int postorder[] = {1, 3, 2, 5, 7, 6, 4};
    int length = sizeof(preorder) / sizeof(preorder[0]);
    
    Node* root = buildTree(preorder, inorder, postorder, length);
    
    printf("Árvore em ordem: ");
    printInorder(root);
    printf("\n");
    
    return 0;
}