#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

typedef struct no {
    unsigned long ende;
    unsigned long ant;
    unsigned long prox;
} no;

int main()
{
    no *v =  malloc(250000 * sizeof(no));
    no ptr1, ptr2;
    int i = 0;

    while(scanf("%lX", &v[i].ende) != EOF && scanf("%lX", &v[i].ant) != EOF && scanf("%lX", &v[i].prox) != EOF)
        i ++;

    ptr1.ende = v[0].ende;
    ptr1.ant = v[0].ant;
    ptr1.prox = v[0].prox;
    ptr2.ende = v[1].ende;
    ptr2.ant = v[1].ant;
    ptr2.prox = v[1].prox;

    if(ptr1.ant == ptr2.prox)
        printf("sana\n");
    else printf("insana\n");

    return 0;
}
