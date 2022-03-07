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

int main()
{
    int n;
    scanf("%d",&n);
    int *v = malloc(n * sizeof(int)), i;
    for(i = 0; i < n; i ++)
        scanf("%d", &v[i]);
    quicksort(v, 0, n-1);
    for(i = 0; i < n; i ++)
        printf("%d ", v[i]);
    return 0;
}
