#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char letra;
    struct node *next;
} Node;

int main(){
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    Node *novo = NULL;
    char entrada[200000];
    scanf("%s", entrada);

    for(long long int i = strlen(entrada)-1; i >= 0; i--){
        novo = (Node *)malloc(sizeof(Node));
        novo->letra = entrada[i];
        novo->next = NULL;
        if(head->next == NULL)
            head->next = novo;
        else{
            novo->next = head->next;
            head->next = novo;
        }

        if(novo->letra == 'A' && novo->next != NULL && novo->next->letra == 'B' && novo->next->next != NULL && novo->next->next->letra == 'C' ){
            Node *temp = head->next;
            head->next = novo->next->next->next;
            while(temp != head->next){
                Node *libera = temp;
                temp = temp->next;
                free(libera);
            }
        }
    
        /*if(curr->letra == 'C'){
            Node *check = checkpoint;
            while (check->next != NULL && check->next->next != NULL && check->next->next->next != NULL) {
                if (check->next->letra == 'A' && check->next->next->letra == 'B' && check->next->next->next->letra == 'C') {
                    Node* temp = check->next;
                    check->next = check->next->next->next->next;
                    while (temp != check->next) {
                        Node* libera = temp;
                        temp = temp->next;
                        free(libera);
                    }
                    curr = check;
                    break;
                } else 
                    check = check->next;
            }  
        }
        if(curr->letra == 'C')
            checkpoint = curr;}*/
    }

    Node *printer = head->next;
    while(printer != NULL){
        printf("%c", printer->letra);
        printer = printer->next;
    } 

    Node *temp = head;
    while(temp != NULL){
        Node *libera = temp;
        temp = temp->next;
        free(libera);
    }
}