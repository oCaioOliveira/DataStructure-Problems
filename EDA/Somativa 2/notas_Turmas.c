#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
char matricula[10];
double mediaAtividades;
double mediaProvas;
struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media) {
  for (le = le -> prox; le != NULL; le = le -> prox) {
    if (le -> mediaAtividades <= media) {
      celula *novo1 = malloc (sizeof(celula));
      for (int i = 0; i < 10; i ++) novo1 -> matricula[i] = le -> matricula[i];
      novo1 -> mediaAtividades = le -> mediaAtividades;
      novo1 -> mediaProvas = le -> mediaProvas;
      novo1 -> prox = l1 -> prox;
      l1 -> prox = novo1;
      l1 = l1 -> prox;
    }
    else {
      celula *novo2 = malloc (sizeof(celula));
      for (int i = 0; i < 10; i ++) novo2 -> matricula[i] = le -> matricula[i];
      novo2 -> mediaAtividades = le -> mediaAtividades;
      novo2 -> mediaProvas = le -> mediaProvas;
      novo2 -> prox = l2 -> prox;
      l2 -> prox = novo2;
      l2 = l2 -> prox;
    }
  }
}