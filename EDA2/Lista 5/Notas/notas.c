#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, notaAlta;
    scanf("%d", &n);

    int *v = malloc(101 * sizeof(int)), i, nota;
    for(i = 0; i < 101; i ++) {
        v[i] = 0;
    }

    for(i = 0; i < n; i ++) {
        scanf("%d", &nota);
        nota = nota % 101;
        v[nota]++;
    }

    int maior = 0;
    for(i = 0; i < 101; i ++) {
        if(v[i] >= maior) {
            maior = v[i];
            notaAlta = i;
        }
    }

    printf("%d\n", notaAlta);

    free(v);

    return 0;
}
