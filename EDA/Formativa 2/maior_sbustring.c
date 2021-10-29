#include <stdio.h>

int olheiro (char str1[], char str2[], int i, int j, int contador, int key)
{
  if (j != 0) olheiro (str1, str2, i - 1, j - 1, contador, key);

  if (str1[i] == str2[j]) return contador ++;
}

int verificasub (char str1[], char str2[], int i, int j , int aux_1, int aux_2, int aux_3, int key, int contador)
{
  if (str1[i] == '\0') return 0;
  else if (key == 0) verificasub (str1, str2, i + 1, j, aux_1, aux_2, aux_3, key, contador);

  if (str2[j] == '\0') return 0;
  else if (key == 0) verificasub (str1, str2, i, j + 1, aux_1, aux_2, aux_3, key, contador);

  key = 1;

  if (str2[j] == str1[i] && str1[i - j] == str2 [0])
  { 
    if (contador > 0) aux_3 = contador;
    
    contador = olheiro (str1, str2, i, j, contador, key);

    if (contador != j + 1) contador = aux_3;
  }
  return contador ++;
}

int main() {
  char str1[102];
  scanf ("%s", str1);

  int i = 0, j = 0, aux_1, aux_2, aux_3, key = 0, contador = 0;

  char str2[101];
  scanf ("%s", str2);

  printf ("%d", verificasub (str1, str2, i, j, aux_1, aux_2, aux_3, key, contador));

  return 0;
}
  