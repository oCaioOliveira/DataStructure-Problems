#include <stdio.h>

int main()

{

    int maior, c, i = 0;
    
    while (scanf("%d", &c) != EOF)
      {
        if (i == 0)
            maior = c;
        else if (c >= maior)
            maior = c;
            
        i ++;

      }
      
    printf ("%d\n", maior);
    
    return 0;
}