#include <stdio.h>
#include <stdlib.h>

int maior (int v[], int n, int r)
{
  for (int i = 0; i < n; i ++) 
    if (v[i] > r) r = v[i];

  return r;
}

void countingSort(int v[], int n, int r)
{
 int valor, i;
  
 int *ocorr_pred = malloc ((r + 1) * sizeof(int)),
 *aux = malloc(n * sizeof(int));
  
 for (valor = 0; valor <= r; valor++) ocorr_pred[valor] = 0;
 
 for (i = 0; i < n; i++)
 {
 valor = v[i];
 ocorr_pred[valor + 1] += 1;
 }
  
 for (valor = 1; valor <= r; valor++) ocorr_pred[valor] += ocorr_pred[valor - 1];
  
 for (i = 0; i < n; i++)
 {
 valor = v[i];
 aux[ocorr_pred[valor]] = v[i];
 ocorr_pred[valor]++;
 }
  
 for (i = 0; i < n; ++i) v[i] = aux[i];
  
 free(ocorr_pred);
 free(aux);
}


int main()
{
  int n, r = 0;

  scanf ("%d", &n);

  if (n <= 0) return 0;

  int *vetor = malloc (n * sizeof(int));

  for (int i = 0; i < n; i ++) scanf ("%d", &vetor[i]);

  for (int i = 0; i < n; i ++) 
    if (vetor[i] > r) r = vetor[i];

  r += 1;

  countingSort (vetor, n, r);

  for (int i = 0; i < n - 1; i ++) printf ("%d ", vetor[i]);
  printf ("%d\n", vetor[n - 1]);

  free(vetor);
  
  return 0;
}

  