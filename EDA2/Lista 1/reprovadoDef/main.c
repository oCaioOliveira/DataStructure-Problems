#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificaOrdem(char nome[101][21], int aux[101], int limite) {
    int i = 0, j;
    while(aux[i] < aux[limite]) {
        for(j = 0; nome[aux[i]][j] != '\0'; j ++) {
            if(nome[aux[i + 1]][j] == '\0') {
                strcpy(nome[aux[i + 1]], nome[aux[i]]);
                break;
            }
            else if(nome[aux[i]][j] > nome[aux[i + 1]][j]) {
                strcpy(nome[aux[i + 1]], nome[aux[i]]);
                break;
            }
            else if(nome[aux[i]][j] == nome[aux[i + 1]][j]) {
                continue;
            }
            else if(nome[aux[i]][j] < nome[aux[i + 1]][j]) {
                break;
            }
        }
        i ++;
    }

    printf("%s\n", nome[aux[limite]]);
}

void verificaReprovado(int numPessoas, char nome[101][21], int numProblemas[101]) {
    int menor = numProblemas[0], j = 0, i;
    int aux[101];
    for(i = 1; i < numPessoas; i ++)
        if(numProblemas[i] < menor) menor = numProblemas[i];

    for(i = 0; i < numPessoas; i ++)
        if(menor == numProblemas[i]) {
            aux[j] = i;
            j ++;
        }

    if(j == 1)
        printf("%s\n", nome[aux[0]]);
    else
        verificaOrdem(nome, aux, j - 1);
}

int main()
{
    int numPessoas;
    int numProblemas[101];
    char nome[101][21];
    int i = 0, j = 1;

    while(scanf("%d", &numPessoas) != EOF) {
        for (i = 0; i < numPessoas; i ++)
            if(scanf("%s", nome[i]) == EOF || scanf("%d",&numProblemas[i]) == EOF)
                return 0;
        printf("Instancia %d\n", j);
        verificaReprovado(numPessoas, nome, numProblemas);
        printf("\n");
        j ++;
    }

    return 0;
}
