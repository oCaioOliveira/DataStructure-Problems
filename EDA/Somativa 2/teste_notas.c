#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
char matricula[10];
double mediaAtividades;
double mediaProvas;
struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media) {
  celula *elem = le -> prox;
  while (elem != NULL) {
    if (elem -> mediaAtividades <= media) {
      l1 -> prox = elem;
      elem = elem -> prox;
      l1 = l1 -> prox;
      l1 -> prox = NULL;
    }
    else {
      l2 -> prox = elem;
      elem = elem -> prox;
      l2 = l2 -> prox;
      l2 -> prox = NULL;
    }
  }
}

