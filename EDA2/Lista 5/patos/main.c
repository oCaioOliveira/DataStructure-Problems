#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

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

    k = 0;

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

void maiorRepeticao(int *v, int n) {
    int i, rep = 0, aux = 0;

    for(i = 0; i < n; i ++) {
        if(aux == 0) {
            rep = v[i];
            aux ++;
        }
        else if(rep == v[i]) {
            aux ++;
        } else
            aux --;
    }

    printf("%d\n", rep);
}

int main()
{
    int n, i;

    scanf("%d", &n);

    while(n != 0) {
        int *v = malloc(n * sizeof(int));

        for(i = 0; i < n; i ++) {
            scanf("%d", &v[i]);
        }

        mergeSort(v, 0, n - 1);

        maiorRepeticao(v, n);

        free(v);

        scanf("%d", &n);
    }

    return 0;
}
