#include <stdio.h>
#include <stdlib.h>

void ordenavetor(int *vetor, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = vetor[(left + right) / 2];
     
    while(i <= j) {
        while(vetor[i] < x && i < right) {
            i++;
        }
        while(vetor[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }
    if(j > left) {
        ordenavetor(vetor, left, j);
    }
    if(i < right) {
        ordenavetor(vetor, i, right);
    }
}

int main()
{
    int numAlunos, i, u, aux = 0;
    int *numID;
    numID = malloc(100000 * sizeof(int));

    scanf("%d", &numAlunos);

    for(i = 0; i < numAlunos; i ++) {
        scanf("%d", &numID[i]);
    }
    
    ordenavetor(numID, 0, numAlunos - 1);

    for (i = 0; i < numAlunos - 1; i ++) 
        if (numID[i] == numID[i + 1]) numID[i] = -1;
        
    for (i = 0; i < numAlunos; i ++) if(numID[i] != -1) aux ++;

aux = aux + 1 - 1 + 2 - 2;
    
    printf("%d\n", aux);

    return 0;
}