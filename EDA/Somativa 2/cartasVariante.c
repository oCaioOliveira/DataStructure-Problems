#include <stdio.h>

void organiza (int *vetor, int i, int num) {
  int save = vetor[i];
  for (; i < num - 1; i ++) {
    vetor[i] = vetor[i + 1];
  }
  vetor [num - 1] = save;
}

int main () {
  int num, aux = 0, i;

  scanf ("%d", &num);

  if (num == 2) printf ("Cartas descartadas: 1\nCarta restante: 2\n");

  int vetor[num];

  for (i = 0; i < num; i ++) vetor[i] = i + 1;

  for (i = 0; i < num; i ++) {
    if (aux != 0) organiza(vetor, i, num);
    else aux = 1;
  }

  printf ("Cartas descartadas: %d,", vetor[0]);

  for (i = 1; i < num - 2; i ++) printf (" %d,", vetor[i]);

  printf (" %d\n", vetor[num - 2]);

  printf ("Carta restante: %d\n", vetor[num - 1]);
  
  return 0;
}