#include <stdio.h>
#include <stdlib.h>

void swap(int *vetor, int posicao, int posicao2) {
    int aux;
    aux = vetor[posicao];
    vetor[posicao] = vetor[posicao2];
    vetor[posicao2] = aux;
}

void ordenacaoSelecao(int *vetor, int tamanho) {
    int i, menor, j;

    for(i = 0; i < tamanho - 1; i ++) {
        menor = i;

        for(j = i + 1; j < tamanho; j ++)
            if(vetor[j] < vetor[menor]) {
                menor = j;
            }
        if(i != menor)
            swap(vetor, i, menor);
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

    ordenacaoSelecao(vetor, i);

    for(j = 0; j < i - 1; j ++)
        printf("%d ", vetor[j]);

    printf("%d\n", vetor[j]);

    free(vetor);

    return 0;
}
