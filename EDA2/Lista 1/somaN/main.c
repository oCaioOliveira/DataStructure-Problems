#include <stdio.h>
#include <stdlib.h>

void somaN(int n) {
    int soma = 0, num, i;
    for(i = 0; i < n; i ++) {
        scanf("%d", &num);
        soma += num;
    }
    printf("%d", soma);
}

int main()
{
    int n;

    scanf("%d", &n);

    somaN(n);

    return 0;
}
