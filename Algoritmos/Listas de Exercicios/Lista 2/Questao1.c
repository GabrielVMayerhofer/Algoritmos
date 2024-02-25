#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    struct node *next;
} Node;

int main(){
    Node *head = NULL;
    Node *curr = NULL;
    Node *novo = NULL;
    Node *tail = (Node *) malloc(sizeof(Node));
    char entry[100001];
    while(scanf("%100000[^\n]%*c", entry) != EOF){
        head = NULL;
        tail = (Node *) malloc(sizeof(Node));
        tail->next = NULL;

        for(long long int i = 0; i < strlen(entry); i++){
            if(entry[i] == '['){
                curr = head;
            }
            else if(entry[i] == ']'){
                curr = tail->next;
            }
            else{
                novo = (Node *) malloc(sizeof(Node));
                novo->data = entry[i];
                novo->next = NULL;
                if(head == NULL){
                    head = (Node *) malloc(sizeof(Node));
                    head->next = novo;
                    curr = novo;
                    tail->next = novo;
                }
                else if(curr == tail->next){
                    tail->next = novo;
                    curr->next = novo;
                    curr = novo;
                }
                else{
                    novo->next = curr->next;
                    curr->next = novo;
                    curr = novo;
                }
            

            }
        }
        
        Node *printer = head->next;
        while(printer != NULL){
            printf("%c", printer->data);
            printer = printer->next;
        }
        printf("\n");

        Node *temp = head;
        while(temp != NULL){
            Node *libera = temp;
            temp = temp->next;
            free(libera);
        }
    }
    free(tail);
}