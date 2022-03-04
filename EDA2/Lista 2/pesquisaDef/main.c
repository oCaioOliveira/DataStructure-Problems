#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) {int t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B);}


void ordenacaoInsercao(int *vetor, int e, int d, int *vetorPos){
    int i, j, aux, auxP;

    for (i = d; i > e; i --) {
        if(less(vetor[i], vetor[i - 1])) {
            exch(vetor[i - 1], vetor[i]);
            exch(vetorPos[i - 1], vetorPos[i]);
        }
    }

    for(i = e + 1; i <= d; i ++) {
        j = i;
        aux = vetor[j];
        auxP = vetorPos[j];
        while(less(aux, vetor[j - 1])) {
            vetor[j] = vetor[j - 1];
            vetorPos[j] = vetorPos[j - 1];
            j --;
        }
        vetor[j] = aux;
        vetorPos[j] = auxP;
    }
}

void buscaBinaria (int *vetor, int tamanho, char str[tamanho][16], int valor, int *vetorPos) {
   int e = -1, d = tamanho, m;

   while (e < d - 1) {
      m = (e + d)/2;

      if (vetor[m] < valor) e = m;
      else d = m;
   }

   if(vetor[d] == valor) printf("%s\n", str[vetorPos[d]]);
   else printf("undefined\n");
}

int main()
{
    int n, i;

    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));
    int *vetorPos = malloc(n * sizeof(int));
    char str[n][16];

    for(i = 0; i < n; i ++) {
        scanf("%d%s", &vetor[i], str[i]);
        vetorPos[i] = i;
    }

    ordenacaoInsercao(vetor, 0, n - 1, vetorPos);

    /*for(i = 0; i < n; i ++)
        printf("%d %d\n", vetor[i], vetorPos[i]);*/

    int valorPesquisa;

    while(scanf("%d", &valorPesquisa) != EOF)
        buscaBinaria(vetor, n, str, valorPesquisa, vetorPos);


    return 0;
}
