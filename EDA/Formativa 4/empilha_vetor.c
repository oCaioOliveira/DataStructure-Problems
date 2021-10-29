#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int empilha (pilha *p, int x) {
  if (p != NULL){
    if (p -> topo == p -> N){
      p -> dados = realloc (p -> dados, 2 * p -> N * sizeof (int));
      if (p -> dados == NULL) return 0;
      p -> N *= 2;
    }
    p -> topo ++;
    p -> dados[p -> topo - 1] = x;
    return 1;
  }
  return 0;
}