#include <stdio.h>

int main() {
  int linhas, colunas, pl, pc, dado, i, j;

  scanf ("%d%d", &linhas, &colunas);

  int matriz[linhas][colunas], vetor[colunas], resultado[linhas];

  for (i = 0; i < linhas; i ++)
  {
    for (j = 0; j < colunas; j ++)
    {  
        matriz[i][j] = 0;
        resultado[i] = 0;
    }
  }

  while (1) {
    scanf ("%d%d%d", &pl, &pc, &dado);
    matriz[pl][pc] = dado;
    
    if (pl == -1 & pc == -1 & dado == -1) break;
  }

  i = 0;
  
  for (i = 0; i < colunas; i ++) scanf ("%d", &vetor[i]);

  //for (i = 0; i < colunas; i ++) printf ("%d ", vetor[i]);

  /*for (i = 0; i < linhas; i ++)
  {
    for (j = 0; j < colunas; j ++)
    {  
        printf ("%d ", matriz[i][j]);
    }
    printf ("\n");
  }*/

  for (i = 0; i < linhas; i ++)
  {
    for (j = 0; j < colunas; j ++)
    {  
        resultado[i] += vetor[j] * matriz[i][j];
    }
  }

  for (i = 0; i < colunas; i ++) printf ("%d\n", resultado[i]);
  
  return 0;
}
  