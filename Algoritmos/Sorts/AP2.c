#include <stdio.h>


int partition(int array[], int low, int high){
    int pivo = array[high];
    int i = low-1;

    for(int j = low; j < high; j++){
        if(array[j] <= pivo){
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return(i+1);
}

void quicksort(int array[], int low, int high){
    if(low < high){
        int part  = partition(array, low, high);
        quicksort(array,low, part-1);
        quicksort(array, part, high);
    }
}

int main(){

}