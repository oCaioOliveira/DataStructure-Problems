#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void buscar (int desordenado[], int n, int busca[], int m, int salvo[], int salvo2[])
{

  int e = -1, d = n + 1, mediano, chave = 0;

  for (int i = 0; i < m; i ++)
  {

    while (e < d - 1)
    {
      
    mediano = (e + d) / 2;
    if (busca[i] > desordenado[mediano]) e = mediano;
    else if (busca[i] < desordenado[mediano]) d = mediano;
    else if (busca[i] == desordenado[mediano]) {busca[i] = mediano; chave = 1; break;}
      
    }

  e = 0; d = n;

  if (chave == 0) busca[i] = -1;

  chave = 0;
    
  }

  for (int i = 0; i < m; i ++)
  {

    if (busca[i] == -1) continue;
    else {
      for (int j = 0; j < n; j ++)
    {

      if (salvo2[i] == salvo[j]) {busca[i] = j; break;}
      
    }
      }
    
  }
  
}

/*int contador(int busca[], int encomendas)
{
  int carteiro = 0, anterior = 0;

  printf ("\n");

  for (int i = 0; i < encomendas; i ++)
{
      printf ("busca: %d ", busca[i]);
  
      if (i == 0) carteiro = busca[i];
      else if (busca[i] > anterior) carteiro += (busca[i] - anterior);
      else if (busca[i] < anterior) carteiro += (anterior - busca[i]);
    
      printf ("%d ", carteiro);
        
      anterior = busca[i];
  }

  printf ("\n\n");
  
  return carteiro;
}*/

int main() {
  
  int tam, ini = 0, m;

  scanf ("%d%d", &tam, &m);

  if (tam <= 0) return 0;

  int *vetor = malloc(tam*sizeof(int)), *busca = malloc(m*sizeof(int)), *salvo = malloc(tam*sizeof(int)), *salvo2 = malloc(m*sizeof(int));

  for (int i = 0; i < tam; i ++) {scanf ("%d", &vetor[i]); salvo[i] = vetor[i];}
  for (int j = 0; j < m; j ++) {scanf ("%d", &busca[j]); salvo2[j] = busca[j];}

  mergeSort (vetor, ini, tam - 1);

  buscar (vetor, tam, busca, m, salvo, salvo2);

  for (int i = 0; i < m; i ++) printf ("%d\n", busca[i]);

  //printf ("%d", contador (busca, m));

  free(vetor); free(busca); free(salvo); free(salvo2);
  
  return 0;
}
  