#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))

void merge(int *v, int *p, int e, int m, int d) {
    int *aux = malloc((d - e + 1) * sizeof(int)), *auxP = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(lessq(v[i], v[j])) {
            auxP[k] = p[i];
            aux[k++] = v[i++];
        }
        else {
            auxP[k] = p[j];
            aux[k++] = v[j++];
        }
    }

    while(i <= m) {
        auxP[k] = p[i];
        aux[k++] = v[i++];
    }

    while(j <= d) {
        auxP[k] = p[j];
        aux[k++] = v[j++];
    }

    k = 0;

    for(i = e; i <= d; i ++) {
        p[i] = auxP[k];
        v[i] = aux[k++];
    }

    free(aux);
    free(auxP);
}


void mergeSort(int *v, int *p, int e, int d) {
    if(e >= d) return;

    mergeSort(v, p, e, (e+d)/2);
    mergeSort(v, p, ((e+d)/2) + 1, d);
    merge(v, p, e, (e+d)/2, d);
}

void buscaBinaria (int *vetor, int *p, int tamanho, int valor) {
   int e = -1, d = tamanho, m;

   while (e < d - 1) {
      m = (e + d)/2;

      if (vetor[m] < valor) e = m;
      else d = m;
   }

   if(vetor[d] == valor) printf("%d\n", p[d]);
   else printf("%d\n", -1);
}

int main()
{
    int n, m, x;

    scanf("%d%d", &n, &m);

    int *vetor = malloc(n * sizeof(int)), *vetorPos = malloc(n * sizeof(int)), i;

    for(i = 0; i < n; i ++) {
        scanf("%d", &vetor[i]);
        vetorPos[i] = i;
    }

    mergeSort(vetor, vetorPos, 0, n - 1);

    for(i = 0; i < m; i ++) {
        scanf("%d", &x);
        buscaBinaria(vetor,vetorPos, n, x);
    }

    free(vetor);

    return 0;
}
