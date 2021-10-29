#include <stdio.h>

int ordenacao (int desordenado[], int n)
{

  int menor, inter, casa, anterior, chave = 0;
  
  for (int i = 0; i < n; i ++)
  {

    menor = desordenado[i];
    
    for (int j = i + 1; j < n; j ++)
    {

      if (menor > desordenado[j] && desordenado[j] > anterior && i != 0) {menor = desordenado[j], casa = j; chave = 1;}
      else if (menor > desordenado[j]) {menor = desordenado[j], casa = j; chave = 1;}      
      
    }

    if (chave == 1)
    {
    inter = desordenado[i];
    desordenado[i] = menor;
    desordenado[casa] = inter;
    chave = 0;
    }
    anterior = desordenado[i];
    
  }
  
}  


int main () 
{

  int desordenado[500], n;

  scanf ("%d", &n);

  for(int i = 0; i < n; i ++) scanf ("%d", &desordenado[i]);

  ordenacao(desordenado, n);

  for(int i = 0; i < n; i ++) {if (i == n - 1) printf ("%d\n", desordenado[i]); else printf ("%d ", desordenado[i]);}
  
  return 0;
  
}