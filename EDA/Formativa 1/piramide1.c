#include <stdio.h>

int main()
{
    int n, i = 1, u = 0;
        
    scanf ("%d", &n);
    
    while (1){
        if (i > n)
            break;
        printf ("%02d ", i);
        u ++;
        if (u == i){
            i ++;
            u = 0;
            printf ("\n");
        }
    }
    
    printf ("\n");
    i = 1;
    u = 1;
    
    while (1){
        printf ("%02d ", i);
        if (i == n)
            break;
        if (i == u){
            i = 1;
            u ++;
            printf ("\n");
            continue;
        }
        i ++;
    }
    
    return 0;
}