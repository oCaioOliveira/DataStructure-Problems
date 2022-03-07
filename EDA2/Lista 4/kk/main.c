#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int separa(int *v,int e,int d)
{
    int aux = v[d], i, j = e;

    /* Reordena o vetor de acordo com um pivo na  ultima posicao deste */
    for(i = e; i < d; i++)
        if(less(v[i], aux))
        {
          exch(v[i], v[j]);
          j++;
        }

    /* Pega o pivo e coloca no lugar onde todos os numeros abaixo dele sao menores e acima sao maiores */
    exch(v[j], v[d]);
    return j;
}

void quicksort(int *v,int e, int d)
{
    if (d <= e) return;

    /* Compara e troca na seguinte sequencia(se for menor):
    Direita com Meio > Meio com Esquerda > Meio com Direita */
    cmpexch(v[(e+d)/2], v[d]);
    cmpexch(v[e], v[(e+d)/2]);
    cmpexch(v[d], v[(e+d)/2]);

    int j = separa(v, e, d);
    quicksort(v, e, j-1);
    quicksort(v, j+1, d);
}

void quickselect(int *v, int e, int d, int x){
    int j;

    if(d <= e) return;

    j = separa(v, e, d);

    if(j > x)
        quickselect(v, e, j - 1, x);
    else if(j < x)
        quickselect(v, j + 1, d, x);
}

int main()
{
    int n, p, x, i;

    scanf("%d%d%d", &n, &p, &x);

    int *v = malloc(n * sizeof(int));

    for(i = 0; i < n; i ++)
        scanf("%d", &v[i]);

    quickselect(v, 0, n - 1, p * x);

    if((p * x) + x > n)
        quickselect(v, (p * x) + 1, n - 1, n);
    else
        quickselect(v, (p * x) + 1, n - 1, (p * x) + x);

    if((p * x) + x > n)
        quicksort(v, p * x, n - 1);
    else
        quicksort(v, p * x, (p * x) + x - 1);

    for(i = p * x; i < n && i < ((p * x) + x); i ++)
        printf("%d\n", v[i]);

    free(v);

    return 0;
}
