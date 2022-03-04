#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    unsigned long ende;
    unsigned long ant;
    unsigned long prox;
} no;

int verificaMenor(no *v, int menor, int tamanho) {
    int i, indice, n;

    for(i = 0; i < tamanho; i ++) {
        if(v[i].ende < menor && v[i].ende != 0) {
            menor = v[i].ende;
            indice = i;
        }
    }

    return indice;
}

int ordenaVetor(no *v, no *vO, int tamanho) {
    int i, j, n, menor = 9999999, tamanhoI = tamanho;

    for(i = 0; i < tamanho; i ++) {
        if(v[i].ant == 0) {
            vO[0].ende = v[i].ende;
            vO[0].ant = v[i].ant;
            vO[0].prox = v[i].prox;
            v[i].ende = 0;
        }
    }

    i = 1;

    for(; i < tamanhoI; i ++) {

        for(j = 0; j < tamanho; j ++) {
            if(vO[i-1].prox == v[j].ende) {
                vO[i].ende = v[j].ende;
                v[j].ende = 0;
                vO[i].ant = v[j].ant;
                vO[i].prox = v[j].prox;
                break;
            }
            else if(j == tamanho - 1) {
                menor = verificaMenor(v, menor, tamanho);
                vO[0].ende = v[menor].ende;
                vO[0].ant = v[menor].ant;
                vO[0].prox = v[menor].prox;
                tamanhoI = tamanhoI - i;
                i = 0;
            }
        }
    }

    for(i = 0; i < tamanhoI; i ++) {
        printf("%X %X %X\n", vO[i].ende, vO[i].ant, vO[i].prox);
    }

    return tamanhoI;
}

int main()
{
    no *v =  malloc(250000 * sizeof(no)), *vO=  malloc(250000 * sizeof(no));
    int i = 0, tamanho;

    while(scanf("%X", &v[i].ende) != EOF && scanf("%X", &v[i].ant) != EOF && scanf("%X", &v[i].prox) != EOF)
        i ++;

    int ptr1 = v[0].ende, ptr2 = v[1].ende;

    tamanho = ordenaVetor(v, vO, i);

    /*removePtrs(vO, tamanho, ptr1, ptr2);*/

    return 0;
}
