#include <stdio.h>

void merge(int array[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int arr1[n1], arr2[n2];
    for(int i = 0; i < n1; i++)
        arr1[i] = array[p + i];
    for(int i = 0; i < n2; i++)
        arr2[i] = array[q + 1 + i];

    int i = 0; int j = 0; int k = p;

    while (i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            array[k] = arr1[i];
            i++;
        }
        else{
            array[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = arr1[i];
        i++; k++;
    }
    while(j < n2){
        array[k] = arr2[j];
        j++; k++;
    }
}

void mergesort(int array[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l, m, r);
    }
}

int main(){
    int casos;
    scanf("%d", &casos);

    
    
    for(int i = 0; i < casos; i++){
        int size;
        scanf("%d", &size);
        int array[size];
        for(int j = 0; j < size; j++){
            scanf("%d", &array[j]);
        }
        mergesort(array, 0, size-1);
        for(int k = 0; k < size; k++){
            printf("%d ", array[k]);
        }
        printf("\n");
    }
    
}