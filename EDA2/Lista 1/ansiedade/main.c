#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, i = 0, aux = 0, triagem = 0, key = 0;
    char resposta[3];

    while (scanf("%d", &c) != EOF) {
            if (i == 10) {
                i = 0;
                key = 0;
                aux = 0;
            }
            scanf("%s", resposta);
            if (resposta[0] == 's') aux ++;
            if (aux >= 2 && key == 0) {
                triagem ++;
                key = 1;
            }
            i ++;
    }

    printf("%d\n", triagem);

    return 0;
}
