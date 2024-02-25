#include <stdio.h>

void merge(long long int array[], long long int p, long long int q, long long int r){
    long long int n1 = q - p + 1;
    long long int n2 = r - q;

    long long int L[n1], M[n2];

    for(long long int i = 0; i < n1; i++)
        L[i] = array[p + i];
    for(long long int j = 0; j < n2; j++)
        M[j] = array[q + 1 +j];

    long long int i, j, k; i = 0; j = 0; k = p;

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

void mergesort(long long int array[], long long int l, long long int r){
    if (l < r) {

    long long int m = l + (r - l) / 2;

    mergesort(array, l, m);
    mergesort(array, m + 1, r);

    merge(array, l, m, r);
  }
}

int main(){
    long long int numBars;
    scanf("%lld", &numBars);
    long long int prices[numBars];
    long long int soma=0;
    for(long long int i = 0; i < numBars; i++){
        scanf("%lld", &prices[i]);
        soma += prices[i];
    }
    
    mergesort(prices, 0, numBars-1);

    long long int numCoupons;
    scanf("%lld", &numCoupons);
    long long int coupons[numCoupons];
    for(long long int i = 0; i < numCoupons; i++)
        scanf("%lld", &coupons[i]);

    for(long long int i = 0; i < numCoupons; i++){
        int result = soma - prices[numBars-coupons[i]];
        printf("%d\n", result);
    }
}