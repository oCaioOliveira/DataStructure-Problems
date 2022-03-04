#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, u, soma = 0;
    char str[100];

    scanf("%d", &n);

    for(i = 0; i < n; i ++) {
        scanf("%s", str);

        for(u = 0; u < 100; u ++) {
            if(str[u] == '\0') break;

            if(str[u] > 48 && str[u] < 58) soma += (str[u] - '0');

        }
        printf ("%d\n", soma);
        soma = 0;
    }

    return 0;
}
