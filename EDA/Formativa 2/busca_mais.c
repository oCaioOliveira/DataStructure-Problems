#include <stdio.h>
#include <stdlib.h>

void countingSort(int v[], int n, int r)
{
 int valor, i;
  
 int *ocorr_pred = malloc ((r + 1) * sizeof(int)),
 *aux = malloc(n * sizeof(int));
  
 for (valor = 0; valor <= r; valor++) ocorr_pred[valor] = 0;
 
 for (i = 0; i < n; i++)
 {
 valor = v[i];
 ocorr_pred[valor + 1] += 1;
 }
  
 for (valor = 1; valor <= r; valor++) ocorr_pred[valor] += ocorr_pred[valor - 1];
  
 for (i = 0; i < n; i++)
 {
 valor = v[i];
 aux[ocorr_pred[valor]] = v[i];
 ocorr_pred[valor]++;
 }
  
 for (i = 0; i < n; ++i) v[i] = aux[i];
  
 free(ocorr_pred);
 free(aux);
}


/*void countingSort(int v[], int n, int r)
{
 int valor, i;
  
 int *ocorr_pred = malloc ((r + 1) * sizeof(int)),
 *aux = malloc(n * sizeof(int));
  
 for (valor = 0; valor <= r; valor++) ocorr_pred[valor] = 0;
 
 for (i = 0; i < n; i++)
 {
 valor = v[i];
 ocorr_pred[valor + 1] += 1;
 }
  
 for (valor = 1; valor <= r; valor++) ocorr_pred[valor] += ocorr_pred[valor - 1];
  
 for (i = 0; i < n; i++)
 {
 valor = v[i];
 aux[ocorr_pred[valor]] = v[i];
 ocorr_pred[valor]++;
 }
  
 for (i = 0; i < n; ++i) v[i] = aux[i];
  
 free(ocorr_pred);
 free(aux);
}

void buscar (int vetor[], int n, int busca[], int m, int salvo[], int salvo2[])
{
  int esq = 0, dir = n + 1, meio, i = 0, j = 0, key = 0;

  while (i < m)
  { 
    meio = (esq + dir) / 2;
    
    if (busca[i] > vetor[meio]) esq = meio;
    else if (busca[i] < vetor[meio]) dir = meio;
    else if (busca[i] == vetor[meio]) {busca[i] = meio; esq = 0; dir = n + 1; i ++; continue;}

    if (esq == (dir - 1) && key == 1) esq = 0, dir = n + 1, i ++, key = 0; 
    else if (esq == (dir - 1) && key == 0) busca[i] = -1, i ++, esq = 0, dir = n + 1;
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
  
}*/

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
  e = 0; d = n;

  if (chave == 0) busca[i] = -1;

  chave = 0;
  }

  for (int i = 0; i < m; i ++)
  {
    if (busca[i] == -1) continue;
    else 
    {
      for (int j = 0; j < n; j ++)
      {

      if (salvo2[i] == salvo[j]) {busca[i] = j; break;}
      
      }
    }
    
  }
  
}*/

void buscar(int v[], int n, int busca[], int m, int salvo[], int salvo2[], int cont) 
{
  if (cont == m) return;
  
  int esq = 0, dir = n, meio; 
  
  while (esq <= dir) 
  {
    int meio = (esq + dir) / 2;

    if (v[meio] == busca[cont]) 
    {
      busca[cont] = meio;
      buscar (v, n, busca, m, salvo, salvo2, cont + 1);
      return;
    }
    else if (v[meio] == v[n - 1] || v[meio] == v[0]) break;
    else if (v[meio] < busca[cont]) esq = meio;
    else if (v[meio] > busca[cont]) dir = meio;
  }
  busca[cont] = -1;
  
  buscar (v, n, busca, m, salvo, salvo2, cont + 1);
}

/*int contador(int busca[], int encomendas)
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
}*/

int main()
{
  int n, r = 0, m, cont = 0;

  scanf ("%d%d", &n, &m);

  if (n <= 0) return 0;

  int *vetor = malloc (n * sizeof(int)),  
  *busca = malloc(m*sizeof(int)), 
  *salvo = malloc(n*sizeof(int)), 
  *salvo2 = malloc(m*sizeof(int));;

  for (int i = 0; i < n; i ++) {scanf ("%d", &vetor[i]); salvo[i] = vetor[i];}
  for (int j = 0; j < m; j ++) {scanf ("%d", &busca[j]); salvo2[j] = busca[j];}

  for (int i = 0; i < n; i ++) 
    if (vetor[i] > r) r = vetor[i];

  r += 1;

  countingSort (vetor, n, r);

  buscar (vetor, n, busca, m, salvo, salvo2, cont);

  for (int i = 0; i < m; i ++)
  {
    if (busca[i] == -1) continue;
    else 
    {
      for (int j = 0; j < n; j ++)
      {
      if (salvo2[i] == salvo[j]) {busca[i] = j; break;}
      }
    }
  }

  for (int i = 0; i < m; i ++) printf ("%d\n", busca[i]);

  //printf ("%d", contador(busca, m));

  free(vetor); free(busca); free(salvo); free(salvo2);
  
  return 0;
}

  