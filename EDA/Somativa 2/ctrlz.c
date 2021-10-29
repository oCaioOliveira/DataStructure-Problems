#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char *dado;
  struct celula *prox;
} celula;


celula *cria_lista () {
  celula *le = malloc (sizeof(celula));
  le -> prox = NULL;
  return le;
}

void desfazer (celula *le) {
  celula *lixo = le -> prox;
  if (lixo != NULL) {
    le -> prox = lixo -> prox;
    printf ("%s\n", lixo -> dado);
    free (lixo);
  }
  else printf ("NULL\n");
}

void inserir (celula *le, char *dado) {
  celula *novo = malloc (sizeof(celula));
  novo -> dado = dado;
  novo -> prox = le -> prox;
  le -> prox = novo;
}

int main () {
  celula *le = cria_lista ();
  char str[100];
  char *aux = malloc(100 * sizeof(char));

  while(1) {
    if (scanf("%s", str) == EOF) break;
    else if (strcmp (str, "inserir") == 0) {
      scanf(" %[^\n]", aux);
      aux [strlen (aux)] = '\0';
      inserir(le, aux);
    }
    else if(strcmp(str,"desfazer")==0) desfazer(le);
    aux = malloc (100 * sizeof(char));
  }
  return 0;
}