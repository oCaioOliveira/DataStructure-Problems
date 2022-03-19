#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))

void merge(int *v, int *vaux, int e, int m, int d) {
    int *aux = malloc((d - e + 1) * sizeof(int));
    int *auxaux = malloc((d - e + 1) * sizeof(int));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(lessq(v[i], v[j])) {
            aux[k] = v[i];
            auxaux[k++] = vaux[i++];
        }
        else {
            aux[k] = v[j];
            auxaux[k++] = vaux[j++];
        }
    }

    while(i <= m) {
        aux[k] = v[i];
        auxaux[k++] = vaux[i++];
    }

    while(j <= d) {
        aux[k] = v[j];
        auxaux[k++] = vaux[j++];
    }

    k = 0;

    for(i = e; i <= d; i ++) {
        v[i] = aux[k];
        vaux[i] = auxaux[k++];
    }

    free(aux);
    free(auxaux);
}


void mergeSort(int *v, int *vaux, int e, int d) {
    if(e >= d) return;

    mergeSort(v, vaux, e, (e+d)/2);
    mergeSort(v, vaux, ((e+d)/2) + 1, d);
    merge(v, vaux, e, (e+d)/2, d);
}

int main() {
    int *v = malloc(100000 * sizeof(int));
    int *vaux = malloc(100000 * sizeof(int));

    int i;
    for(i = 0; i < 100000; i ++) {
        v[i] = 0;
        vaux[i] = 0;
    }

    int s, f, e, p = 1;
    scanf("%d%d%d", &s, &f, &e);
    int saux = s, faux = f, eaux = e;

    int *vs = malloc(s * sizeof(int));
    int *vf = malloc(f * sizeof(int));
    int *ve = malloc(e * sizeof(int));

    int numVoto, votoValido = 0, votoInvalido = 0, votoPresidentes = 0;
    while(scanf("%d", &numVoto) != EOF) {
        if(numVoto < 0) {
            votoInvalido ++;
            continue;
        }
        else {
            v[numVoto] ++;
            vaux[numVoto] = numVoto;
            votoValido ++;
            if(numVoto > 0 && numVoto < 100)
                votoPresidentes ++;
        }
    }

    mergeSort(v, vaux, 0, 99999);

    printf("%d %d\n", votoValido, votoInvalido);

    int k = 0, u = 0, n = 0;
    for(i = 99999; i >= 0; i --) {
        if(v[i] == 0)
            break;
        else if(vaux[i] > 0 && vaux[i] < 100 && p > 0) {
            float porcentagem = (v[i] * 1.0) / (votoPresidentes * 1.0);
            if(porcentagem > 0.5)
                printf("%d\n", vaux[i]);
            else
                printf("Segundo turno\n");

            p --;
        }
        else if(vaux[i] > 99 && vaux[i] < 1000 && s > 0) {
            vs[k ++] = vaux[i];
            s --;
        }
        else if(vaux[i] > 999 && vaux[i] < 10000 && f > 0) {
            vf[u ++] = vaux[i];
            f --;
        }
        else if(vaux[i] > 9999 && vaux[i] < 100000 && e > 0) {
            ve[n ++] = vaux[i];
            e --;
        }
    }

    printf("%d", vs[0]);
    for(i = 1; i < saux; i ++)
        printf(" %d", vs[i]);
    printf("\n");

    printf("%d", vf[0]);
    for(i = 1; i < faux; i ++)
        printf(" %d", vf[i]);
    printf("\n");

    printf("%d", ve[0]);
    for(i = 1; i < eaux; i ++)
        printf(" %d", ve[i]);
    printf("\n");

    return 0;
}
