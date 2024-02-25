//Exemplo, Questao 1, AP 6
#define TAM 10
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} Node;

typedef struct list{
    int chave;
    Node *nextNode;
    struct list *nextList;
} Lista;


int main(){
    Lista *head = (Lista *) malloc(sizeof(Lista));
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    head->nextList = lista;
    lista->chave = 0;
    lista->nextNode = NULL;
    Lista *temp = lista;
    for(int i = 1; i < TAM; i++){
        Lista *novo = (Lista *) malloc(sizeof(Lista));
        novo->chave = i;
        novo->nextNode = NULL;
        temp->nextList = novo;
        temp = novo;
    }

    long int numEntry;
    scanf("%ld", &numEntry);

    for(long int j = 0; j < numEntry; j++){
        int entry;
        scanf("%d", &entry);
        int inserir = entry % 10;
        Lista *currList = head->nextList;
        Node *novo = (Node *) malloc(sizeof(Node));
        novo->valor = entry;
        novo->next = NULL;

        while(currList != NULL){
            if(inserir == currList->chave){
                Node *currNode = currList->nextNode;
                if(currNode == NULL){
                    currList->nextNode = novo;
                }
                else{
                    while(currNode->next != NULL)
                        currNode = currNode->next;
                    currNode->next = novo;
                }
                break;
            }
            currList = currList->nextList;
        }
    }

    Lista *currList = head->nextList;
    while(currList != NULL){
        Node *currNode = currList->nextNode;
        printf("%d ", currList->chave);
        while(currNode != NULL){
            printf("%d ", currNode->valor);
            currNode = currNode->next;
        }
        printf("\n");
        currList = currList->nextList;
    }

    currList = head;
    while(currList != NULL){
        Node *currNode = currList->nextNode;
        while(currNode != NULL){
            Node *help = currNode;
            currNode = currNode->next;
            free(help);
        }
        Lista *aux = currList;
        currList = currList->nextList;
        free(aux);        
    }
    free(head);

}

