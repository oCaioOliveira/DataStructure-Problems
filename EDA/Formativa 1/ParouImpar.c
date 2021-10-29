#include <stdio.h>

int main()
{
    int ndejogos, j1, j2, i = 0, t = 1;
    char nome1[30], nome2[30];
    
    while (1){
        scanf ("%d", &ndejogos);
        
        if (ndejogos == 0)
            break;
            
        scanf ("%s%s", nome1, nome2);
        
        printf ("Teste %d\n", t);
        
        while (i < ndejogos){
            
            scanf ("%d%d", &j1, &j2);
            
            if ((j1 + j2) % 2 == 0)
                printf ("%s\n", nome1);
            else 
                printf ("%s\n", nome2);
            i ++;
        }
        
        t ++;
        i = 0;
        
    }
    
    return 0;
}