#include <stdio.h>
#include <stdlib.h>

int ler(int *vetor) {
    int i;
    for (i = 0;; i ++) {
        scanf ("%d", &vetor[i]);

        if (vetor[i] == 0) {
            scanf ("%d", &vetor[i + 1]);
            return vetor[i + 1];
        }
    }
}

void verificaSoma(int *vetor, int pos, int lim) {
    int i, soma = 0;
    for (i = pos; i < 10000; i ++) {
        if (vetor[i] == 0) break;
        soma += vetor[i];
        if(soma > lim) {
            pos = i + 1;
            verificaSoma(vetor, pos, lim);
            printf("%d\n", vetor[i]);
            break;
        }
    }
}

int main()
{
    int tam = 10000, pos = 0, limite;
    int *vetor;
    vetor = malloc(tam * sizeof(int));

    limite = ler(vetor);

    verificaSoma(vetor, pos, limite);

    return 0;
}