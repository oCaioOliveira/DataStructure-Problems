#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, c;

    while (scanf("%d", &c) != EOF) i ++;

    printf ("%d\n", i);

    return 0;
}
