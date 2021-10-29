#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
  celula *elem;

  for (elem = le -> prox; elem != NULL; elem = elem -> prox)
    if (x == elem -> dado) return elem;
  
  return elem;
}

celula *busca_rec (celula *le, int x) {
  celula *elem = le -> prox;

  if (elem == NULL) return NULL;
  if (x == elem -> dado) return elem;

  busca_rec (elem, x);
}