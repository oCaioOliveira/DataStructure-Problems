#include <stdio.h>

int main()
{
    int numero, i , n, resultado, j, t = 1;
    char op[0];
    
    for (i; i; i)
    {
        
        scanf ("%d", &i);
        
        if (i == 0 || i > 50)
            break;
            
        scanf ("%d", &numero);
        resultado = numero;
        
        for (j = 1; j < i; j ++)
        {
            
            scanf ("%s", op);
            scanf ("%d", &numero);
            
            if (op[0] == '+')
                resultado = resultado + numero;
            else
                resultado = resultado - numero;
            
        }
        
        printf ("Teste %d\n%d\n", t, resultado);
        t ++;
        
    }
    
    return 0;
    
}