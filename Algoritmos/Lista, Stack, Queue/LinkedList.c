#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *criar(Node *head, Node *novo, Node *tail, Node *curr, int entrada){
    novo = (Node *) malloc(sizeof(Node));
    novo->data = entrada;
    novo->next = NULL;
    if(head == NULL){ //inicializa
        head = (Node *) malloc(sizeof(Node));
        head->next = novo;
        curr = novo;
        tail->next = novo;
    }
    else if(curr == tail->next){ //add no final
        tail->next = novo;
        curr->next = novo;
        curr = novo;
    }
    else{ //add no comeco
        novo->next = curr->next;
        curr->next = novo;
        curr = novo;
    }
}

void print(Node *head){
    Node *printer = head->next;
    while(printer != NULL){
        printf("%c", printer->data);
        printer = printer->next;
    }
    printf("\n");
}

void libera(Node *head){
    Node *temp = head;
    while(temp != NULL){
        Node *libera = temp;
        temp = temp->next;
        free(libera);
    }
}

int main(){
    Node *head = NULL;
    Node *curr = NULL;
    Node *novo = NULL;
    Node *tail = (Node *) malloc(sizeof(Node));
    tail->next = NULL;
    int entry;
    for(int i = 0; i < entry; i++)
        inserir(head, novo, tail, curr, entry);
    
    print(head);
    libera(head);
    free(tail);
}