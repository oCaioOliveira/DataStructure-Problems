#include <stdio.h>

int main(void) {
  char x;
  char vetor[501];
  int u = 0, key = 0, extra = 0;
  
  while(x != '\n'){
    scanf("%c", &x);
    if(x=='{' || x=='[' || x=='(' 
    || x=='}' || x==']' ||x==')')
      vetor[u ++] = x;
  }

  for (int i = 0; i < 501; i ++) {
    if (vetor[i] == '\0') {printf ("sim\n"); break;}

    if (key != 0) {printf ("nao\n"); return 0;}
    
    if (vetor[i] == '('){
      for (int j = i + 1; j; j ++) {
        if (vetor[j] == '{' || vetor[j] == '[') key ++;
        if (vetor[j] == '}' || vetor[j] == ']') key --;
        if (vetor[j] == '(') extra ++;
        if (vetor[j] == ')' && extra == 0) {
          vetor[j] = '0';
          break;
        }
        if (vetor[j] == ')') extra --;
        if (vetor[j] == '\0') {printf ("nao\n"); return 0;}
      }
    }

    if (vetor[i] == '['){
      for (int j = i + 1; j; j ++) {
        if (vetor[j] == '{' || vetor[j] == '(') key ++;
        if (vetor[j] == '}' || vetor[j] == ')') key --;
        if (vetor[j] == '[') extra ++;
        if (vetor[j] == ']' && extra == 0) {
          vetor[j] = '0';
          break;
        }
        if (vetor[j] == ']') extra --;
        if (vetor[j] == '\0') {printf ("nao\n"); return 0;}
      }
    }

    if (vetor[i] == '{'){
      for (int j = i + 1; j; j ++) {
        if (vetor[j] == '[' || vetor[j] == '(') key ++;
        if (vetor[j] == ']' || vetor[j] == ')') key --;
        if (vetor[j] == '{') extra ++;
        if (vetor[j] == '}' && extra == 0) {
          vetor[j] = '0';
          break;
        }
          if (vetor[j] == '}') extra --;
        if (vetor[j] == '\0') {printf ("nao\n"); return 0;}
      }
    }

    if (vetor[i] == '}' || vetor[i] == ']' || vetor[i] == ')') {printf ("nao\n"); return 0;}
  }
}