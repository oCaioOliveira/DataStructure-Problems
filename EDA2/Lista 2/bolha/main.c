#include <stdio.h>
#include <stdlib.h>

void swap(int *vetor, int posicao) {
    int aux;
    aux = vetor[posicao];
    vetor[posicao] = vetor[posicao + 1];
    vetor[posicao + 1] = aux;
}

void ordenacaoBolha(int *vetor, int tamanho) {
    int i = 0, chave = 1;

    while(chave == 1) {
        chave = 0;

        for(i = 0; i < tamanho - 1; i ++)
            if(vetor[i] > vetor[i + 1]) {
                chave = 1;
                swap(vetor, i);
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

    ordenacaoBolha(vetor, i);

    for(j = 0; j < i - 1; j ++)
        printf("%d ", vetor[j]);

    printf("%d\n", vetor[j]);

    free(vetor);

    return 0;
}
