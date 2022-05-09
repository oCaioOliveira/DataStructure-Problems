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
    int n, i;

    scanf("%d", &n);

    int v[n];

    for(i = 0; i < n; i ++)
        scanf("%d", &v[i]);

    mergeSort(v, 0, n - 1);

    for(i = 1; i < n - 1; i ++)
        if((v[i-1] + v[i]) > v[i+1]) {
            printf("YES\n");
            return 0;
        }

    printf("NO\n");

    return 0;
}
