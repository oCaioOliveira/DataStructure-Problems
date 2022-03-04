#include <stdio.h>
#include <stdlib.h>

void swap(int *vetor, int posicao, int posicao2) {
    int aux;
    aux = vetor[posicao];
    vetor[posicao] = vetor[posicao2];
    vetor[posicao2] = aux;
}

void ordenacaoInsercao(int *vetor, int tamanho) {
    int i, j, aux;

    for(i = 1; i < tamanho; i ++) {
        if(vetor[i] < vetor[i - 1]) {
            swap(vetor, i, i - 1);
            aux = i - 1;
            for(j = i - 2; j >= 0; j --) {
                if(vetor[j] < vetor[aux]) {
                    break;
                }
                else if(vetor[j] > vetor[aux]) {
                    swap(vetor, j, aux);
                    aux = j;
                }
            }
        }
    }
}

int main()
{
    int *vetor, i = 0, tamanho = 10, j;
    vetor = malloc(tamanho * sizeof(int));

    while(scanf("%d", &vetor[i]) != -1) {
        if(i == tamanho - 1) {
            tamanho = tamanho * 2;
            vetor = realloc(vetor, tamanho * sizeof(int));
        }
        i ++;
    }

    ordenacaoInsercao(vetor, i);

    for(j = 0; j < i - 1; j ++)
        printf("%d ", vetor[j]);

    printf("%d\n", vetor[j]);

    free(vetor);

    return 0;
}
