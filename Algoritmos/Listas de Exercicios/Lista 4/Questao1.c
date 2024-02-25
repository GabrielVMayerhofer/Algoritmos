#include <stdio.h>
#include <stdlib.h>

typedef struct leaf{
    long int key;
    int height;
    int size;
    struct leaf* left;
    struct leaf* right;
}Folha;

int max(int a, int b);

int height(Folha* folha){
    if(folha == NULL)
        return -1;
    return folha->height;
}

int size(Folha* folha) {
    if(folha == NULL)
        return 0;
    return folha->size;
}

Folha *criarFolha(int elemento);
Folha *rightRotate(Folha *folha);
Folha *leftRotate(Folha *folha);
int getBalance(Folha *folha);
Folha *inserir(Folha *root, long int elemento);
int find(Folha *root, long int elemento);
void limpa(Folha *folha);

int main(){
    Folha *root = NULL;
    long long int vezes;
    scanf("%lld", &vezes);
    for(long long int i = 0; i < vezes; i++){
        int entry;
        long int data;
        scanf("%d %ld", &entry, &data);
        int index;

        switch(entry){
            case 1:
                root = inserir(root, data);
                break;

            case 2:
                index = find(root, data);

                if(index == -1)
                    printf("Data tidak ada\n");
                else
                    printf("%d\n", index);
                break;
        }

    }
    limpa(root);
    return 0;
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
    temp->size = 1;
    return temp;
}

Folha *rightRotate(Folha *folha){
    Folha *temp = folha->left;
    Folha *temp2 = temp->right;

    temp->right = folha;
    folha->left = temp2;

    folha->height = max(height(folha->left), height(folha->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    folha->size = size(folha->left) + size(folha->right) + 1;
    temp->size = size(temp->left) + size(temp->right) + 1;

    return temp;
}

Folha *leftRotate(Folha *folha){
    Folha *temp = folha->right;
    Folha *temp2 = temp->left;

    temp->left = folha;
    folha->right = temp2;

    folha->height = max(height(folha->left), height(folha->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    
    folha->size = size(folha->left) + size(folha->right) + 1;
    temp->size = size(temp->left) + size(temp->right) + 1;

    return temp;
}

int getBalance(Folha *folha){
    if(folha == NULL)
        return 0;
    return height(folha->left) - height(folha->right);
}

Folha *inserir(Folha *root, long int elemento){
    if(root == NULL)
        return criarFolha(elemento);
        
    if(root->key > elemento)
        root->left = inserir(root->left, elemento);
    else
        root->right = inserir(root->right, elemento);

    root->height = max(height(root->left), height(root->right)) + 1;
    root->size = size(root->left) + size(root->right) + 1;

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

int find(Folha *root, long int elemento){
    if (root == NULL)
        return -1;

    if (elemento < root->key)
        return find(root->left, elemento);
    else if (elemento > root->key){    
        int rightIndex = find(root->right, elemento);
        return (rightIndex == -1) ? -1 : size(root->left) + 1 + rightIndex;
    }
    else
        return size(root->left) + 1;
}

void limpa(Folha *folha){
    if(folha != NULL){
        limpa(folha->left);
        limpa(folha->right);
        free(folha);
    }
}