#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
  celula *novo = malloc (sizeof(celula));
  if (novo==NULL) exit(1);
  novo -> dado = x;
  novo -> prox = le -> prox;
  le -> prox = novo;
}

void insere_antes (celula *le, int x, int y) {
  celula *adiantado = le -> prox, *novo = malloc (sizeof(celula));

  while (adiantado != NULL) {
    if (adiantado -> dado == y) {
      novo -> dado = x;
      novo -> prox = le -> prox;
      le -> prox = novo;
      return;
    }
    adiantado = adiantado -> prox;
    le = le -> prox;
  }

  novo -> dado = x;
  novo -> prox = le -> prox;
  le -> prox = novo;
}
