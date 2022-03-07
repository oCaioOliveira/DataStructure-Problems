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

int verificaIgual(int *v,int tamanho) {
    int i, j = 1;
    int *vAux = malloc(tamanho * sizeof(int));

    vAux[0] = v[0];
    for(i = 1; i < tamanho; i ++) {
        if(v[i] != vAux[j-1]) {
            vAux[j++] = v[i];
        }
    }

    for(i = 0; i < j; i ++)
        v[i] = vAux[i];

    free(vAux);

    return j;
}

int geraVetorSoma(int *v, int n) {
    int *vR = malloc((n/2) * sizeof(int));
    int i, j = 0;

    for(i = 0; i < (n/2); i ++) {
        vR[i] = v[j] + v[j+1];
        j += 2;
    }

    j = 0;

    for(i = n; i < (n+(n/2)); i ++)
        v[i] = vR[j++];

    n = n + (n/2);

    free(vR);

    return n;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *v = malloc(200000 * sizeof(int)), i;

    for(i = 0; i < n; i ++)
        scanf("%d", &v[i]);

    quicksort(v, 0, n-1);

    n = verificaIgual(v, n);

    if(n % 2 != 0)
        v[n++] = 1000000000;

    n = geraVetorSoma(v, n);

    quicksort(v, 0, n-1);

    n = verificaIgual(v, n);

    for(i = 0; i < n; i += 4)
        printf("%d\n", v[i]);

    printf("Elementos: %d\n", n);

    free(v);

    return 0;
}
