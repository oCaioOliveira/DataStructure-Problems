#include <stdio.h>

char inverso(char palavra[100], char arvalap[100], int n, int i, int s)
{

  // Ajuste...
  if (s == n  / 2) return arvalap[100];
  else if (palavra[n + s] == '\0')
  {

    arvalap[i + s] = palavra[n - s - 1];
    s += 1;
    inverso(palavra, arvalap, n, i, s);
    
  }
  else
  {

    n += 1;
    inverso(palavra, arvalap, n, i, s);
      
  }
    
}

int main()
{

  int n = 0, i = 0, s = 0;
  
  char palavra[100], arvalap[100];

  scanf ("%s", palavra);

  printf ("%s" ,inverso(palavra, arvalap, n, i, s));

  return 0;
  
}