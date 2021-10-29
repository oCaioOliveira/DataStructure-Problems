#include <stdio.h>

 

int main()
{
    int numero, i = 1, n = 1, resultado, t = 1;
    char op;
    
    while (n != 0)
    {
        
        scanf ("%d", &n);
        
        if (n == 0 || n > 100)
            break;
            
        scanf ("%d", &numero);
        resultado = numero;
        
        while (i < n)
        {
            
            if (n != 1)
            {
                scanf (" %c", &op);
                scanf ("%d", &numero);

                if (op == '+')
                resultado = resultado + numero; 
                else if (op == '-')
                resultado = resultado - numero;

                i ++;
                
            }
            else
                break;
        }
        
        i = 1;
        printf ("Teste %d\n%d\n", t, resultado);
        t ++;
        
    }
    
    return 0;
    
}