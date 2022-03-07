#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lessq(A,B) (key(A) <= key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

typedef struct No {
    int tamanho;
    char letra[1];
    int pos;
} No;

void merge(No estrutura[100000], int e, int m, int d) {
    No *aux = malloc((d - e + 1) * sizeof(No));
    int i = e, j = m + 1, k = 0;

    while(i <= m && j <= d) {
        if(lessq(estrutura[i].tamanho, estrutura[j].tamanho)) {
            aux[k].letra[0] = estrutura[i].letra[0];
            aux[k].pos = estrutura[i].pos;
            aux[k++].tamanho = estrutura[i++].tamanho;
        } else {
            aux[k].letra[0] = estrutura[j].letra[0];
            aux[k].pos = estrutura[j].pos;
            aux[k++].tamanho = estrutura[j++].tamanho;
        }
    }

    while(i <= m) {
        aux[k].letra[0] = estrutura[i].letra[0];
        aux[k].pos = estrutura[i].pos;
        aux[k++].tamanho = estrutura[i++].tamanho;
    }

    while(j <= d) {
        aux[k].letra[0] = estrutura[j].letra[0];
        aux[k].pos = estrutura[j].pos;
        aux[k++].tamanho = estrutura[j++].tamanho;
    }

    k = 0;

    for(i = e; i <= d; i ++) {
        estrutura[i].letra[0] = aux[k].letra[0];
        estrutura[i].pos = aux[k].pos;
        estrutura[i].tamanho = aux[k++].tamanho;
    }

    free(aux);
}


void mergeSort(No estrutura[100000], int e, int d) {
    if(e >= d) return;

    mergeSort(estrutura, e, (e+d)/2);
    mergeSort(estrutura, ((e+d)/2) + 1, d);
    merge(estrutura, e, (e+d)/2, d);
}

void separaLetra(char str[100000], No estrutura[100000]) {
    int i, k = 0, ini, fim, n, auxP, auxT, j;
    char auxL[1];

    estrutura[0].letra[0] = str[0];
    estrutura[0].tamanho = 1;
    estrutura[0].pos = 0;

    for(i = 1; str[i] != '\0'; i ++) {
        if(str[i] != estrutura[k].letra[0]) {
            k ++;
            estrutura[k].letra[0] = str[i];
            estrutura[k].pos = i;
            estrutura[k].tamanho = 1;
        } else {
            estrutura[k].tamanho ++;
        }
    }

    mergeSort(estrutura, 0, k);

    fim = k;
    for(i = k; i >= 0; i --) {
        if(estrutura[i].tamanho != estrutura[i-1].tamanho) {
            for(j = i; j <= fim; j ++)
                printf("%d %c %d\n", estrutura[j].tamanho, estrutura[j].letra[0], estrutura[j].pos);
            fim = i - 1;
        } else if(i == 0)
            for(j = 0; j <= fim; j ++)
                printf("%d %c %d\n", estrutura[j].tamanho, estrutura[j].letra[0], estrutura[j].pos);
    }
}

int main()
{
    char str[100000];
    No estrutura[100000];

    scanf("%s", str);

    separaLetra(str, estrutura);

    return 0;
}
