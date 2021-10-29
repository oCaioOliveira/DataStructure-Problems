#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *vetor, int ini, int fim) 
{

    int i, j, k, mediano;

    if(ini == fim) return;

    mediano = (ini + fim ) / 2;

    mergeSort(vetor, ini, mediano); 
    mergeSort(vetor, mediano + 1, fim); 

    i = ini; j = mediano + 1; k = 0;
    int *vetorTemp = malloc(sizeof(int) * (fim - ini + 1));

    while(i < mediano + 1 || j  < fim + 1) {
        if (i == mediano + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else if (j == fim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else if (vetor[i] < vetor[j]) {
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
    for(i = ini; i <= fim; i++) {
        vetor[i] = vetorTemp[i - ini];
    }
    free(vetorTemp);
}

/*void buscar (int desordenado[], int n, int busca[], int m, int salvo[], int salvo2[])
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

  e = 0; d = n + 1;

  if (chave == 0) busca[i] = -1;

  chave = 0;
    
  }*/


void buscar (int vetor[], int n, int busca[], int m, int salvo[], int salvo2[])
{
  int esq = 0, dir = n + 1, meio, i = 0, j = 0;

  while (i < m)
  { 
    meio = (esq + dir) / 2;
    
    if (busca[i] > vetor[meio]) esq = meio;
    else if (busca[i] < vetor[meio]) dir = meio;
    else if (busca[i] == vetor[meio]) {busca[i] = meio; esq = 0; dir = n + 1; i ++; continue;}

    //if (esq == (dir - 1) && key == 1) esq = 0, dir = n + 1, i ++, key = 0; 
    //else if (esq == (dir - 1) && key == 0) busca[i] = -1, i ++, esq = 0, dir = n + 1;
  }

  for (i = 0; i < m; i ++)
  {

    if (busca[i] == -1) continue;
    else {
      for (j = 0; j < n; j ++)
    {

      if (salvo2[i] == salvo[j]) {busca[i] = j; break;}
      
    }
      }
    
  }
  
}

int contador(int busca[], int encomendas)
{
  int carteiro = 0, anterior = 0;

  printf ("\n");

  for (int i = 0; i < encomendas; i ++)
{
      //printf ("busca: %d ", busca[i]);
  
      if (i == 0) carteiro = busca[i];
      else if (busca[i] > anterior) carteiro += (busca[i] - anterior);
      else if (busca[i] < anterior) carteiro += (anterior - busca[i]);
    
      //printf ("%d ", carteiro);
        
      anterior = busca[i];
  }

  //printf ("\n\n");
  
  return carteiro;
}

int main() {
  
  int tam, ini = 0, m;

  scanf ("%d%d", &tam, &m);

  if (tam <= 0) return 0;

  int *vetor = malloc(tam*sizeof(int)),
  *busca = malloc(m*sizeof(int)), 
  *salvo = malloc(tam*sizeof(int)), 
  *salvo2 = malloc(m*sizeof(int));

  for (int i = 0; i < tam; i ++) {scanf ("%d", &vetor[i]); salvo[i] = vetor[i];}
  for (int j = 0; j < m; j ++) {scanf ("%d", &busca[j]); salvo2[j] = busca[j];}

  mergeSort (vetor, ini, tam - 1);

  buscar (vetor, tam, busca, m, salvo, salvo2);

  //for (int i = 0; i < m; i ++) printf ("%d\n", busca[i]);

  printf ("%d", contador(busca, m));

  free(vetor); free(busca); free(salvo); free(salvo2);
  
  return 0;
}
