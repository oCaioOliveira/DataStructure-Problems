#include <stdio.h>

int inverso(char s[], int i)
{

  if (s[i] != '\0')
    inverso(s, i + 1);
  else 
    return 0;

  printf ("%c", s[i]);
  
} 

int main()
{

  char palavra[501];

  scanf ("%s", palavra);

  inverso(palavra, 0);

  return 0;

}