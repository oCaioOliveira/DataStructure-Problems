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

void buscaBinaria (int *vetor, int tamanho, int valor) {
   int e = -1, d = tamanho, m;

   while (e < d - 1) {
      m = (e + d)/2;

      if (vetor[m] < valor) e = m;
      else d = m;
   }

   if(vetor[d] == valor) printf("sim\n");
   else printf("nao\n");
}

int main()
{
    int n, x;

    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int)), i;

    for(i = 0; i < n; i ++) {
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, n - 1);

    while(scanf("%d", &x) != EOF) {
        buscaBinaria(vetor, n, x);
    }

    free(vetor);

    return 0;
}
