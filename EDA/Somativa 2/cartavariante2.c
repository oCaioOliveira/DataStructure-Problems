#include <stdio.h>
#include <stdlib.h>

void organiza (int *vetor, int i, int num) {
  vetor[num] = vetor[i];
  vetor[i] = 0;
}

int main () {
  int num, aux = 0, i;

  scanf ("%d", &num);

  if (num == 2) printf ("Cartas descartadas: 1\nCarta restante: 2\n");

  int *vetor = malloc (num * 10 * sizeof(int));

  for (i = 0; i < num; i ++) vetor[i] = i + 1;

  for (i = 0; ; i ++) {
    if (i == num) break;
    
    if (aux != 0) {aux = 0; organiza(vetor, i, num); num ++;}
    else if (aux == 0) {aux = 1;}
  }

  printf ("Cartas descartadas: %d,", vetor[0]);

  for (i = 1; i < num - 3; i ++) 
    if (vetor[i] != 0) printf (" %d,", vetor[i]);

  printf (" %d\n", vetor[num - 3]);

  printf ("Carta restante: %d\n", vetor[num - 1]);
  
  return 0;
}