#include <stdio.h>

int bsearch(int array[], int key, int l, int r, int counter){
    if(r>=l){
        int m = (l+r)/2;
        if(array[m] == key){
            return (counter+1);
        }
        else if(key < array[m]){
            return bsearch(array, key, l, m-1, counter);
        }
        else{
            return bsearch(array, key, m+1, r, counter);
        }
    }
    else return counter;
}


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
    long long int n;
    int k;
    scanf("%lld %d", &n, &k);
    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    mergesort(nums, 0, n-1);
    int numPares = 0;
    for(int i = 0; i < n; i++)
        numPares = bsearch(nums, nums[i] + k, 0, n-1, numPares);
    
    printf("%d", numPares);
}