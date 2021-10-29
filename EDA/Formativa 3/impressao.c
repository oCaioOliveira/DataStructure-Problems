#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int imprime (celula *le) {
  celula *elem = le -> prox;

  if (elem == NULL) return printf ("NULL\n");
  else printf ("%d", elem -> dado);
  
  for (elem = elem -> prox; elem != NULL; elem = elem -> prox)
    printf (" -> %d", elem -> dado);
  printf (" -> NULL\n");
}

int imprime_rec (celula *le) {
  celula *elem = le -> prox;

  if (elem == NULL) return printf ("NULL\n");
  else printf ("%d", elem -> dado);

  printf (" -> ");

  imprime_rec (elem);
}  