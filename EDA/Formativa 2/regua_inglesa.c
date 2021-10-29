#include <stdio.h>

void regua(int n)
{

  if (n == 0) printf ("");
  else if (n == 1) printf (".-\n");
  else 
  {
    regua(n - 1);

    printf (".");

    for (int i = 0; i < n; i ++) printf ("-");

    printf ("\n");

    regua(n - 1);
  }
  
}

int main()
{

    int num;
  
    scanf ("%d", &num);

    regua(num);

    return 0;
  
}