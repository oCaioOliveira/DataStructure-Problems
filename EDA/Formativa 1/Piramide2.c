#include <stdio.h>

int main()
{
    int n, i = 1, j, u, l = 0;
    
    scanf ("%d", &n);
    
    u = n;
    j = n;
    
    while (1){
        
        if (l == n)
        break;
        
        if (i < u){
            printf (" ");
            i ++;
        }
        
        if (i >= u && i <= j){
            printf ("*");
            i ++;
        }
        
        if (i > j){
            printf ("\n");
            u --;
            j ++;
            i = 1;
            l ++;
        }
        
    }
    
    return 0;
}