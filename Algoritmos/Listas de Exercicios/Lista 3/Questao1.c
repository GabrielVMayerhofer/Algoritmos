#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    char element[16];
    int cheio;
} List;

int hash(char pala[]);

int main(){
    int cases;
    scanf("%d", &cases);
        
    for(int k = 0; k < cases; k++){
        int ops;
        scanf("%d", &ops);
        List lista[101];
        for(int i = 0; i < 101; i++)
            lista[i].cheio = 0;

        for(int j = 0; j < ops; j++){
            char operacao[5];
            scanf("%4s", operacao);
            char palavra[16];
            scanf("%s", palavra);

            int posicao = hash(palavra);

            if(strcmp(operacao, "ADD:") == 0){
                int jaExiste = 0;
                for(int q = 0; q < 20; q++){
                    int check = (posicao + (q*q) + (23 * q)) % 101;
                    if(lista[check].cheio == 1 && strcmp(lista[check].element, palavra) == 0){
                        jaExiste = 1;
                        break;
                    }
                }

                if(jaExiste == 0){
                    for(int q = 0; q < 20; q++){
                        int novaPosicao = (posicao + (q*q) + (23 * q)) % 101;
                        if(lista[novaPosicao].cheio == 0){
                            strcpy(lista[novaPosicao].element, palavra); 
                            lista[novaPosicao].cheio = 1;
                            break;
                        }
                    }
                }
            }
            else if(strcmp(operacao, "DEL:") == 0){
                for(int q = 0; q < 20; q++){
                    int novaPosicao = (posicao + (q*q) + (23 * q)) % 101;
                    if(lista[novaPosicao].cheio == 1 && strcmp(lista[novaPosicao].element, palavra) == 0){
                        strcpy(lista[novaPosicao].element, "*"); 
                        lista[novaPosicao].cheio = 0;
                        break;
                    }
                }
            }
        }

        int num = 0;
        for(int p = 0; p < 101; p++)
            if(lista[p].cheio == 1)
                num++;
        printf("%d\n", num);
        for(int p = 0; p < 101; p++)
            if(lista[p].cheio == 1)
                printf("%d:%s\n", p, lista[p].element);  
    }
}

int hash(char pala[]){
    int total = 0;
    for(int i = 0; i < strlen(pala); i++)
        total += ((int)pala[i] * (i+1));
    int posicao = (19 * total) % 101;
    return posicao;
}