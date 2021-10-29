#include <stdio.h>

int soma(long int n)
{

  if (n == 0) return 0;
  else return n % 10 + soma(n / 10);
  
}

int main()
{

  long int num;

  scanf ("%ld", &num);

  if (num == 0) printf ("0");
  else printf ("%d", soma(num));

  return 0;
  
}