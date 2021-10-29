#include <stdio.h>

int main()
{
    int c1, c2, c3, c4, maior, menor;
    
    scanf ("%d%d%d%d", &c1, &c2, &c3, &c4);
    
    if (c1 >= c2 && c1 >= c3 && c1 >= c4)
        maior = c1;
    else if (c2 >= c1 && c2 >= c3 && c2 >=c4)
        maior = c2;
    else if (c3 >= c1 && c3 >= c2 && c3 >= c4)
        maior = c3;
    else if (c4 >= c1 && c4 >= c2 && c4 >= c3)
        maior = c4;
        
    printf ("%d", maior);
    
    return 0;
}