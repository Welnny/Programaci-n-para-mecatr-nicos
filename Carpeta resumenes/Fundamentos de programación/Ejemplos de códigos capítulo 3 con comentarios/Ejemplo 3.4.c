#include <stdio.h>
#include <math.h>

/* Suma cuadrados.
El programa, al recibir datos como un grupo de enteros positivos, obtiene el cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */

void main(void)
{
int NUM;
long CUA, SUC = 0;
printf("\nIngrese un n�mero entero -0 para terminar-:\t");
scanf("%d", &NUM);
while (NUM)
/* Observa que la condici�n es verdadera mientras el entero es diferente de cero. */
{
       CUA = pow (NUM, 2);
       printf("%d al cubo es %ld", NUM, CUA);
       SUC = SUC + CUA;
       printf("\nIngrese un n�mero entero -0 para terminar-:\t");
       scanf("%d", &NUM);
}
printf("\nLa suma de los cuadrados es %ld", SUC);
}
/*"Aqu� "while" se ejecutar� mientras que NUM no sea igual a 0, en este caso "while" calcula y acumula la suma de cuadrados hasta que se ingrese 0.*/
