#include <stdio.h>
#include <stdlib.h>

void ordenacaoInsercao(int *vetor, int tamanho){
    int i, j, aux;
    for (i = 1; i < tamanho; i++) {
        aux = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j --;
        }
        vetor[j + 1] = aux;
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
