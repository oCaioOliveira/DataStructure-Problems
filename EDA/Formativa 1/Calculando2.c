#include <stdio.h>

int main()
{
    int numero, i = 1, n = 1, resultado, t = 1;
    char operador[0];
    
    while (1)
    {
        
        scanf ("%d", &n);
        
        if (n == 0 || n > 100)
            break;
            
        scanf ("%d", &numero);
        resultado = numero;
        
        while (i < n)
        {
            
                scanf ("%s %d", operador, &numero);
                
                if (operador[0] == '+')
                resultado = resultado + numero; 
                else
                resultado = resultado - numero;
                
                i ++;

        }
        
        i = 1;
        printf ("Teste %d\n%d\n", t, resultado);
        t ++;
        
    }
    
    return 0;
    
}