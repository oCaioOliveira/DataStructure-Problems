#include <stdlib.h>
#include <stdio.h>

typedef struct fila {
int *dados;
int N, p, u;
} fila;

int filaCheia(fila *f){
    if((f->u + 1)% f->N == f->p) return 1;
    else return 0;
}

int redimensiona(fila *f){
    f->dados = realloc(f->dados, (f->N) * 2 * sizeof(int));
    if (f->dados == NULL) return 0; 

    int tam = ((f->N - 1) - f->p);
    int n = f->N;
    f->N *= 2;

    if(f->p < f->u) return 1;

    if (f->u < tam ){
        for(int i = 0; i <= f->u; i++){
            f->dados[n + i] = f->dados[i];
        }
        f->u += n;
        return 1;
    }

    if(tam < f->u){
        for(int i = f->p; i < n; i++){
            f->dados[(f->N - 1) - tam] = f-> dados[i];
            tam--;
        }
        f->p += n;
        return 1;
    }    
}

int enfileira (fila *f, int x){
    if (filaCheia(f))
        if(!redimensiona(f)) return 0;
    f->dados[f->u] = x;
    f -> u = (f -> u + 1) % f -> N;
    return 1;    
}