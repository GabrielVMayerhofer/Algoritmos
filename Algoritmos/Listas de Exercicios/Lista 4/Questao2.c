#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapify(int lista[], int vezes) {
    int k, v;
    for (int i = floor(vezes / 2); i > 0; i--) {
        k = i;
        v = lista[k];
        int heap = 0;

        while (heap == 0 && 2 * k <= vezes) {
            int j = 2 * k;
            if (j < vezes && lista[j] > lista[j + 1]) {
                j += 1;
            }
            if (v <= lista[j]) {
                heap = 1;
            } else {
                lista[k] = lista[j];
                k = j;
            }
        }
        lista[k] = v;
    }
}

int main() {
    int vezes;

    while (1) {
        scanf("%d", &vezes);

        if (vezes == 0) {
            break;
        }

        int lista[vezes + 1];
        for (int i = 1; i <= vezes; i++) {
            scanf("%d", &lista[i]);
        }

        int cost = 0;
        heapify(lista, vezes);

        while (vezes > 1) {
            int menor1 = lista[1];
            int menor2;

            lista[1] = lista[vezes];
            vezes--;

            heapify(lista, vezes);

            menor2 = lista[1];

            int soma = menor1 + menor2;
            cost += soma;

            lista[1] = soma;

            heapify(lista, vezes);
        }

        printf("%d\n", cost);
    }

    return 0;
}