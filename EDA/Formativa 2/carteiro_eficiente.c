#include <stdio.h>
#include <stdlib.h>

int contador (int casa[], int n, int encomenda[], int m)
{
  int carteiro = 0, anterior = 0, j;

  for (int i = 0; i < m; i ++)
  {
    if (i == 0)
    {
      for (j = 0; j < n; j ++)
      {
        if (encomenda[0] == casa[j]) {carteiro = j; break;}
      }
    }
    else
    {
      for (j = 0; j < n; j ++)
      {
        if (encomenda[i] == casa[j])
        {
          if (j > anterior) carteiro += j - anterior;
          else if (j < anterior) carteiro += anterior - j;
          break;
        } 
      }
    }
    anterior = j;
  }

  printf ("\n");
  
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
  