#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void remove_depois (celula *p) {
  celula *lixo = p -> prox;
  if (lixo != NULL) {
    p -> prox = lixo -> prox;
    free (lixo);
  }
}

void remove_elemento (celula *le, int x) {
  for (celula *elem = le; elem -> prox != NULL; elem = elem -> prox) {
    if (elem -> prox -> dado == x) {
      remove_depois (elem);
      return;
    }
  }
}

void remove_todos_elementos  (celula *le, int x) {
for (celula *elem = le; elem -> prox != NULL;) {
    if (elem -> prox -> dado == x & elem -> prox != NULL)
      remove_depois (elem); 
    else elem = elem -> prox;
  }
}  