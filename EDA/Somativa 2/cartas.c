#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *criaPilha () {
  celula *le = malloc (sizeof(celula));
  le -> prox = NULL;
  return le;
}

void insere_inicio (celula *le, int x) {
  celula *novo = malloc (sizeof(celula));
  if (novo==NULL) exit(1);
  novo -> dado = x;
  novo -> prox = le -> prox;
  le -> prox = novo;
}

void imprime (celula *le) {
  celula *elem = le -> prox;

  if (elem == NULL)printf ("NULL\n");
  else printf ("%d", elem -> dado);
  
  for (elem = elem -> prox; elem != NULL; elem = elem -> prox)
    printf (" -> %d", elem -> dado);
  printf (" -> NULL\n");
}

void insere_final (celula *le, int x) {
  celula *novo = malloc (sizeof(celula));
  for (; le != NULL; le = le -> prox) {
    if (le -> prox == NULL) {
      novo -> dado = x;
      novo -> prox = le -> prox;
      le -> prox = novo;
      break;
    }
  }
}

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

int main () {
  celula *p = malloc(sizeof(celula)), *aux = malloc(sizeof(celula));
  p = criaPilha ();
  int num, j = 0;

  scanf("%d", &num);

  for (int i = num; i > 0; i --) insere_inicio(p, i);

  if (num == 2) {
    printf("Cartas descartadas: %d\nCarta restante: %d\n", p -> prox -> dado, p -> prox -> prox -> dado);
    return 0;
  }

  imprime (p);

  printf ("\n");

  for (aux = p -> prox; aux != NULL; aux = aux -> prox) {
    printf ("p -> dado = %d\n", aux -> dado);
    if (j == 0) {
      j = 1;
    }
    else {
      insere_final (p, aux -> dado);
      remove_elemento (p, aux -> dado);
      j = 0;
    }
    imprime (aux);
    imprime (p);
  }

  printf ("\n");

  imprime(p);
  
  return 0;
}
  
  