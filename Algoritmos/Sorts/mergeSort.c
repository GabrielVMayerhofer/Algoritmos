#include <stdio.h>

void merge(int array[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for(int i = 0; i < n1; i++)
        L[i] = array[p + i];
    for(int j = 0; j < n2; j++)
        M[j] = array[q + 1 +j];

    int i, j, k; i = 0; j = 0; k = p;

    while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
        array[k] = L[i];
        i++;
      } else {
        array[k] = M[j];
        j++;
      }
      k++;
    }
    
    while (i < n1) {
      array[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      array[k] = M[j];
      j++;
      k++;
    }

}

void mergesort(int array[], int l, int r){
    if (l < r) {

    int m = l + (r - l) / 2;

    mergesort(array, l, m);
    mergesort(array, m + 1, r);

    merge(array, l, m, r);
  }
}

int main(){
    
    int array[7] = {8, 7, 5, 6, 2, 4, 3};
    mergesort(array, 0, 6);
    for(int i = 0; i < 7; i++)
        printf("%d ", array[i]);
}