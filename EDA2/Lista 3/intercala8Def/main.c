#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))

void merge(int *v, int e, int m, int d) {
    int *aux = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(lessq(v[i], v[j]))
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while(i <= m)
        aux[k++] = v[i++];

    while(j <= d)
        aux[k++] = v[j++];

    k = 0; /*IPC*/

    for(i = e; i <= d; i ++)
        v[i] = aux[k++];

    free(aux);
}


void mergeSort(int *v, int e, int d) {
    if(e >= d) return;

    mergeSort(v, e, (e+d)/2);
    mergeSort(v, ((e+d)/2) + 1, d);
    merge(v, e, (e+d)/2, d);
}

int main()
{
    int tamanho = 10;
    int *vetor = malloc(tamanho * sizeof(int)), i = 0, n, j = 0, soma = 0;

    while(i < 8) {
        scanf("%d", &n);

        soma += n;

        for(; j < soma; j ++) {
            if(j == tamanho - 1) {
                tamanho *= 2;
                vetor = realloc(vetor, tamanho * sizeof(int));
            }
            scanf("%d", &vetor[j]);
        }
        i ++;
    }

    mergeSort(vetor, 0, j - 1);

    for(i = 0; i < j; i ++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}

