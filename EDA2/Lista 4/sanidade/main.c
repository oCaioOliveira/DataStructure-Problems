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

int buscaBinaria(no *v, int tamanho, int valor) {
   int e = -1, d = tamanho, m;

   while (e < d - 1) {
      m = (e + d)/2;

      if (v[m].ende < valor) e = m;
      else d = m;
   }

   if(v[d].ende == valor) return d;
   else return -1;
}

/*void verificaNo(no *v, int tamanho, no ptr1, no ptr2) {
    int pos, *vA = malloc(250000 * sizeof(int)), *vB = malloc(250000 * sizeof(int)), i = 0, j = 0, k;

    pos = buscaBinaria(v, tamanho, ptr1.prox);

    while(pos != -1) {
        if(v[pos].ende == ptr2.ende) {
            pos = buscaBinaria(v, tamanho, v[pos].ant);
            while(pos != -1) {
                if(v[pos].ende == ptr1.ende) {
                    if(i == j) {
                        j --;
                        for(k = 0; k < i; k ++) {
                            if(vA[k] == vB[j--])
                                continue;
                            else {
                                printf("insana\n");
                                return;
                            }
                        }
                        printf("sana\n");
                        return;
                    }
                    else {
                        printf("insana\n");
                        return;
                    }
                }
                vB[j++] = v[pos].ende;
                pos = buscaBinaria(v, tamanho, v[pos].ant);
            }
        }
        vA[i++] = v[pos].ende;
        pos = buscaBinaria(v, tamanho, v[pos].prox);
    }

    printf("insana\n");
}*/

void verificaNo(no *v, int tamanho, no ptr1, no ptr2) {
    int pos;
    unsigned long *vA = malloc(250000 * sizeof(unsigned long)), *vB = malloc(250000 * sizeof(unsigned long)), i = 1, j = 1, k;

    vA[0] = ptr1.prox;
    pos = buscaBinaria(v, tamanho, ptr1.prox);

    while(pos != -1) {
        if(v[pos].ende == ptr2.ende) {
            vB[0] = ptr2.ant;
            pos = buscaBinaria(v, tamanho, ptr2.ant);
            while(pos != -1) {
                if(v[pos].ende == ptr1.ende) {
                    if(i == j) {
                        j -= 2;
                        for(k = 0; k < i - 1; k ++) {
                            if(vA[k] != vB[j]) {
                                printf("insana\n");
                                return;
                            }
                            else if(k == i - 2 && vA[k] == vB[j]) {
                                printf("sana\n");
                                return;
                            }
                            j --;
                        }
                    }
                    else {
                        printf("insana\n");
                        return;
                    }
                }

                vB[j++] = v[pos].ant;
                pos = buscaBinaria(v, tamanho, v[pos].ant);
            }

            printf("insana\n");
            return;
        }

        vA[i++] = v[pos].prox;
        pos = buscaBinaria(v, tamanho, v[pos].prox);
    }

    pos = buscaBinaria(v, tamanho, ptr2.prox);

    printf("insana\n");
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
    int aux;

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
    int i = 0, j;

    while(scanf("%lX", &v[i].ende) != EOF && scanf("%lX", &v[i].ant) != EOF && scanf("%lX", &v[i].prox) != EOF)
        i ++;

    ptr1.ende = v[0].ende;
    ptr1.ant = v[0].ant;
    ptr1.prox = v[0].prox;
    ptr2.ende = v[1].ende;
    ptr2.ant = v[1].ant;
    ptr2.prox = v[1].prox;

    quicksort(v, 0, i - 1);

    /*if(ptr1.prox == ptr2.ant)
        printf("sana\n");
    else
        printf("insana\n");*/

    verificaNo(v, i, ptr1, ptr2);

    return 0;
}
