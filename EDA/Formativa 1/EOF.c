#include <stdio.h>

int main()

{

    int i = 0, c;
    
    while (c != EOF)
      {
          
        c = getchar();
        
        if (c == '\n')
            i ++;

      }
      
    printf ("%d\n", i);
    
    return 0;
}