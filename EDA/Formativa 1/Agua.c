#include <stdio.h>

int main()
{
    int agua, preco = 7, acrescimo;
    
    scanf ("%d", &agua);
    
    if (agua < 11)
        printf ("%d", preco);
    else if (agua > 10 && agua < 31)
        printf ("%d", preco + agua - 10);
    else if (agua > 30 && agua < 101)
        printf ("%d", preco + 20 + (agua - 30) * 2);
    else if (agua > 100)
        printf ("%d", preco + 160 + (agua - 100) * 5);
    return 0;
}