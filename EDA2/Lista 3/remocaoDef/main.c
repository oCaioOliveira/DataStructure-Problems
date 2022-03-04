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

int buscaBinaria(no *v, int tamanho, long unsigned valor) {
   int e = -1, d = tamanho, m;

   while (e < d - 1) {
      m = (e + d)/2;

      if (v[m].ende < valor) e = m;
      else d = m;
   }

   if(v[d].ende == valor) return d;
   else return -1;
}

void verificaNo(no *v, int tamanho, no ptr1, no ptr2) {
    int pos, i = 0, j, aux, cont = 0, tamanhoI;
    long unsigned vA[250000];
    no *vD =  malloc(250000 * sizeof(no)), *vAux =  malloc(250000 * sizeof(no));

    pos = buscaBinaria(v, tamanho, ptr1.prox);
    aux = pos;
    vA[i++] = ptr1.ende;
    vA[i++] = v[pos].ende;

    while(pos != -1) {
        if(v[pos].ende == ptr2.ende) {
            break;
        }
        pos = buscaBinaria(v, tamanho, v[pos].prox);
        vA[i++] = v[pos].ende;
    }

    tamanhoI = i;

    aux = buscaBinaria(v, tamanho, ptr1.ant);
    v[aux].prox = v[pos].prox;
    pos = buscaBinaria(v, tamanho, ptr2.prox);
    v[pos].ant = v[aux].ende;

    pos = aux;

    pos = buscaBinaria(v, tamanho, v[pos].ant);

    while(pos != -1) {
        vAux[cont].ende = v[pos].ende;
        vAux[cont].ant = v[pos].ant;
        vAux[cont++].prox = v[pos].prox;
        pos = buscaBinaria(v, tamanho, v[pos].ant);
    }

    j = 0;
    for(i = cont - 1; i >= 0; i --) {
        vD[j].ende = vAux[i].ende;
        vD[j].ant = vAux[i].ant;
        vD[j++].prox = vAux[i].prox;
    }

    i = cont;
    pos = aux;
    vD[i].ende = v[pos].ende;
    vD[i].ant = v[pos].ant;
    vD[i++].prox = v[pos].prox;
    pos = buscaBinaria(v, tamanho, v[pos].prox);

    while(pos != -1) {
        vD[i].ende = v[pos].ende;
        vD[i].ant = v[pos].ant;
        vD[i++].prox = v[pos].prox;
        pos = buscaBinaria(v, tamanho, v[pos].prox);
    }

    for(j = 0; j < i; j ++)
        printf("%lX %lX %lX\n", vD[j].ende, vD[j].ant, vD[j].prox);

    printf("\n");

    for(j = 0; j < tamanhoI; j ++)
        printf("%lX\n", vA[j]);
}

int separa(no *v,int e,int d)
{
    long unsigned pivo = v[d].ende, aux;
    int i, j = e;

    /* Reordena o vetor de acordo com um pivo na  ultima posicao deste */
    for(i = e; i < d; i++)
        if(less(v[i].ende, pivo))
        {
            aux = v[j].ende;
            v[j].ende = v[i].ende;
            v[i].ende = aux;
            aux = v[j].ant;
            v[j].ant = v[i].ant;
            v[i].ant = aux;
            aux = v[j].prox;
            v[j].prox = v[i].prox;
            v[i].prox = aux;
            j++;
        }

    /* Pega o pivo e coloca no lugar onde todos os numeros abaixo dele sao menores e acima sao maiores */
    aux = v[j].ende;
    v[j].ende = v[d].ende;
    v[d].ende = aux;
    aux = v[j].ant;
    v[j].ant = v[d].ant;
    v[d].ant = aux;
    aux = v[j].prox;
    v[j].prox = v[d].prox;
    v[d].prox = aux;
    return j;
}

void quicksort(no *v,int e, int d)
{
    if (d <= e) return;
    long unsigned aux;

    /* Compara e troca na seguinte sequencia(se for menor):
    Direita com Meio > Meio com Esquerda > Meio com Direita */
    if(v[d].ende < v[(e+d)/2].ende) {
        aux = v[(e+d)/2].ende;
        v[(e+d)/2].ende = v[d].ende;
        v[d].ende = aux;
        aux = v[(e+d)/2].ant;
        v[(e+d)/2].ant = v[d].ant;
        v[d].ant = aux;
        aux = v[(e+d)/2].prox;
        v[(e+d)/2].prox = v[d].prox;
        v[d].prox = aux;
    }

    if(v[(e+d)/2].ende < v[e].ende) {
        aux = v[(e+d)/2].ende;
        v[(e+d)/2].ende = v[e].ende;
        v[e].ende = aux;
        aux = v[(e+d)/2].ant;
        v[(e+d)/2].ant = v[e].ant;
        v[e].ant = aux;
        aux = v[(e+d)/2].prox;
        v[(e+d)/2].prox = v[e].prox;
        v[e].prox = aux;
    }

    if(v[(e+d)/2].ende < v[d].ende) {
        aux = v[(e+d)/2].ende;
        v[(e+d)/2].ende = v[d].ende;
        v[d].ende = aux;
        aux = v[(e+d)/2].ant;
        v[(e+d)/2].ant = v[d].ant;
        v[d].ant = aux;
        aux = v[(e+d)/2].prox;
        v[(e+d)/2].prox = v[d].prox;
        v[d].prox = aux;
    }

    int j = separa(v, e, d);
    quicksort(v, e, j-1);
    quicksort(v, j+1, d);
}

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

    quicksort(v, 0, i - 1);

    verificaNo(v, i, ptr1, ptr2);

    return 0;
}
