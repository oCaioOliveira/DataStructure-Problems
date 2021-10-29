#include <stdio.h>
#include <stdlib.h>

void insertionSort (int vetor[], int n) {

  int liga, j;

  for(int i = 1; i < n; i ++){

    liga = vetor[i];

    for ( j = i - 1; j >= 0 && liga < vetor[j]; j --){

      vetor[j + 1] = vetor[j];
      
    }

    vetor[j + 1] = liga;
    
  }
 
}

int main() {
  
  int n;

  scanf ("%d", &n);

  if (n <= 0) return 0;

  int *vetor = malloc(n*sizeof(int));

  for (int i = 0; i < n; i ++) scanf ("%d", &vetor[i]);

  insertionSort (vetor, n);

  for (int i = 0; i < n - 1; i ++) printf ("%d ", vetor[i]);
  printf ("%d\n", vetor[n - 1]);

  free(vetor);
  
  return 0;
}
  