#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int coluna;
  int valor;
  struct celula *prox;
} celula;

void inserir (celula *le, int x, int y) {
  celula *novo = malloc (sizeof(celula));
  if (novo != NULL) {
    novo -> coluna = x;
    novo -> valor = y;
    novo -> prox = le -> prox;
    le -> prox = novo;
  }
}

int main() {
    int m, n, linha, coluna, valor;
  int *vetor, *result;
  scanf ("%d%d", &m, &n);
  
  celula *matriz = malloc (m * sizeof(celula));
  vetor = malloc (n * sizeof(int));
  result = malloc (m * sizeof(int));
  
  for (int i = 0; i < m; i ++) {
    matriz[i].prox = NULL;
  }

  while (1) {
    scanf ("%d%d%d", &linha, &coluna, &valor);
    if (linha == -1 && coluna == -1 && valor == -1) break;
    else inserir (&matriz[linha], coluna, valor);
  }

  for (int i = 0; i < n; i ++) {
    scanf ("%d", &vetor[i]);
  }

  for (int i = 0; i < m; i ++) {
    celula *aux = matriz[i].prox;
    int soma = 0;
    while (aux != NULL) {
      soma += aux -> valor * vetor[aux -> coluna];
      aux = aux -> prox;
    }
    result[i] = soma;
  }

  for (int i = 0; i < m; i ++) {
    printf ("%d\n", result[i]);
  }
  
  return 0;
}
  