#include <stdio.h>

int verifica (char *exp) {
  for (int i = 0; i < 501; i ++) {
    if (exp[i] == '\0') break;
    
    if (exp[i] == '('){
      for (int j = i + 1; j; j ++) {
        if (exp[j] == ')') {
          exp[j] = '0';
          break;
        }

        if (exp[j] == '\0') return 0;
      }
    }

    if (exp[i] == '['){
      for (int j = i + 1; j; j ++) {
        if (exp[j] == ']') {
          exp[j] = '0';
          break;
        }

        if (exp[j] == '\0') return 0;
      }
    }

    if (exp[i] == '{'){
      for (int j = i + 1; j; j ++) {
        if (exp[j] == '}') {
          exp[j] = '0';
          break;
        }

        if (exp[j] == '\0') return 0;
      }
    }
  }
  return 1;
}

int main() {
  char *exp;  

  scanf ("%s", exp);

  if (verifica (exp)) printf ("sim");
  else printf ("nao");
  
  return 0;
}
  