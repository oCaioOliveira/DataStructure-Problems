#include <stdio.h>

float potencia( float a, float b )
{
    if (b == 0) return 1;
    else if (b > 0) return a * potencia(a, b - 1);
    else if (b < 0) return a * potencia(a, b + 1);
}

int main()
{
    int num1, num2;
    
    scanf ("%d%d", &num1, &num2);
  
    if (num2 == 0 & num1 == 0) printf ("indefinido");
    else if (num2 == 0 & num1 != 0) printf ("1");
    else if (num2 > 0) printf ("%f", potencia(num1, num2));
    else if (num2 < 0) printf ("%f", 1/potencia(num1, num2));

    return 0;
}