#include <stdio.h>
#include <stdlib.h>

typedef struct leaf{
    int key;
    int height;
    struct leaf* left;
    struct leaf* right;
}Folha;

int max(int a, int b);

int height(Folha* folha){
    if(folha == NULL)
        return -1;
    return folha->height;
}

Folha *criarFolha(int elemento);
Folha *rightRotate(Folha *folha);
Folha *leftRotate(Folha *folha);
int getBalance(Folha *folha);
Folha *inserir(Folha *root, int elemento);
void printPreOrder(Folha *root);

int main(){
    Folha *root = NULL;

    root = inserir(root, 2);
    root = inserir(root, 1);
    root = inserir(root, 7);
    root = inserir(root, 4);
    root = inserir(root, 5);
    root = inserir(root, 3);
    root = inserir(root, 8);

    printPreOrder(root);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Folha *criarFolha(int elemento){
    Folha *temp = (Folha *) malloc(sizeof(Folha));
    temp->key = elemento;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    return temp;
}

Folha *rightRotate(Folha *folha){
    Folha *temp = folha->left;
    Folha *temp2 = temp->right;

    temp->right = folha;
    folha->left = temp2;

    folha->height = max(height(folha->left), height(folha->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

Folha *leftRotate(Folha *folha){
    Folha *temp = folha->right;
    Folha *temp2 = temp->left;

    temp->left = folha;
    folha->right = temp2;

    folha->height = max(height(folha->left), height(folha->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    
    return temp;
}

int getBalance(Folha *folha){
    if(folha == NULL)
        return 0;
    return height(folha->left) - height(folha->right);
}

Folha *inserir(Folha *root, int elemento){
    if(root == NULL)
        return criarFolha(elemento);
        
    if(root->key > elemento)
        root->left = inserir(root->left, elemento);
    else
        root->right = inserir(root->right, elemento);

    root->height = 1 + max(height(root->left), height(root->right));
    
    int balance = getBalance(root);

    if(balance > 1 && elemento < root->left->key)
        return rightRotate(root);
    if(balance < -1 && elemento >= root->right->key)
        return leftRotate(root);

    if (balance > 1 && elemento >= root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && elemento < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printPreOrder(Folha *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}