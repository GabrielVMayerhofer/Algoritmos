#include <stdio.h>
#include <stdlib.h>

typedef struct leaf{
    long long int valor;
    struct leaf* Left;
    struct leaf* Right;
} Folha;

Folha *insert(Folha *link, int elemento);
Folha *criarFolha(int elemento);
void preorder(Folha *root);
void inorder(Folha *root);
void posorder(Folha *root);
void limpa(Folha *root);


int main(){
    int folhas;
    scanf("%d", &folhas);
    long long int numeros[folhas];
    for(int i = 0; i < folhas; i++)
        scanf("%lld", &numeros[i]);
    
    Folha *root = NULL;

    for(int i = 0; i < folhas; i++)
        root = insert(root, numeros[i]);
    
    printf("Pre order :");
    preorder(root);
    printf("\nIn order  :");
    inorder(root);
    printf("\nPost order:");
    posorder(root);
    
    limpa(root);
}

void preorder(Folha *root){
    if(root != NULL){
        printf(" %lld", root->valor);
        preorder(root->Left);
        preorder(root->Right);
    }
}

void inorder(Folha *root){
    if(root != NULL){
        inorder(root->Left);
        printf(" %lld", root->valor);
        inorder(root->Right);
    }
}

void posorder(Folha *root){
    if(root != NULL){
        posorder(root->Left);
        posorder(root->Right);
        printf(" %lld", root->valor);
    }
}

Folha *criarFolha(int elemento){
    Folha *temp = (Folha *) malloc(sizeof(Folha));
    temp->valor = elemento;
    temp->Left = NULL;
    temp->Right = NULL;
    return temp;
}

Folha *insert(Folha *folha, int elemento){
    if(folha == NULL)
        return criarFolha(elemento);
    if(elemento < folha->valor)
        folha->Left = insert(folha->Left, elemento);
    else
        folha->Right = insert(folha->Right, elemento);
    return folha;
}

void limpa(Folha *root){
    if(root != NULL){
        limpa(root->Left);
        limpa(root->Right);
        free(root);
    }
}