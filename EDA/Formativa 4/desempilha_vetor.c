#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int desempilha (pilha *p, int *y) {
  if (p != NULL) {
    if (p -> topo == 0)
      return 0;
    else {
      *y = p -> dados[p -> topo - 1];
      p -> topo --;
      return 1;
    }
  }
  return 0;
}