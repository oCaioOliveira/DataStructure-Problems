#include <stdio.h>
#include <stdlib.h>

int contador (int casa[], int n, int encomenda[], int m)
{
  int carteiro = 0, anterior = 0, j = 0, i= 0;

  while (i < m)
  {

    if (encomenda[i] == casa[j]) 
    {
      if (j > anterior)
      {
        carteiro += j - anterior; 
        anterior = j;
        j = 0; 
        i ++; 
        continue;
      }
      else if (j < anterior) 
      {
        carteiro += anterior - j;
        anterior = j;
        j = 0; 
        i ++; 
        continue;
      } 
      else {carteiro = j; anterior = j; j = 0; i ++; continue;}
    }
    j ++;
  }
  
  return carteiro;
}

int main() 
{
  int n, m;
  scanf ("%d%d", &n, &m);

  int *casa = malloc (n*sizeof(int)), *encomenda = malloc (m*sizeof(int));

  for (int i = 0; i < n; i ++) scanf ("%d", &casa[i]);
  for (int i = 0; i < m; i ++) scanf ("%d", &encomenda[i]);
  
  printf ("%d\n", contador (casa, n, encomenda, m));
  
  return 0;
}
  