#include <stdio.h>

int contador(long int num, int somador)
{

  if (num == 0) return printf ("%d", somador);
  else 
  {
    
  int sete = num % 10;

  if (sete == 7) somador ++;
  
  contador(num / 10, somador);

  }
  
} 

int main()
{

  int somador = 0;
  long int num;

  scanf ("%ld", &num);
  
  contador(num, somador);
  
  return 0;

}