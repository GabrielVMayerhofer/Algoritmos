#include <stdio.h>

int main(){
    int index;
    printf("quantos?\n");
    scanf("%d", &index);
    int array[index];
    printf("quais?\n");
    for(int i = 0; i < index; i++)
        scanf("%d", &array[i]);
    int min;
    for(int j = 0; j < index; j++){
        min = array[j];
        int indexMin = j;
        for(int k = j + 1; k < index; k++){
            if(array[k] < min){
                indexMin = k;
                min = array[k];
            }
        }
        int swap = array[j];
        array[j] = min;
        array[indexMin] = swap;
    }
    for(int i = 0; i < index; i++)
        printf("%d ", array[i]);
}