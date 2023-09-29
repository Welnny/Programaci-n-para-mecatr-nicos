#include <stdio.h>

#include <stdio.h>

/* Nómina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la nómina de la universidad.

I: variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main(void)
{
int I;
float SAL, NOM;
NOM = 0;
for (I=1; I<=15; I++)
{
     printf("\Ingrese el salario del profesor%d:\t", I);
     scanf("%f", &SAL);
     NOM = NOM + SAL;
}
printf("“\nEl total de la nómina es: %.2f", NOM);

}
/* En este caso "for" se encarga de repetir 15 veces un conjunto de instrucciones, debido a que I<=15 es la condición "for" seguirá ejecutándose siempre y cuando la variable I sea menor o igual a 15. Entonces "for" se ejecutará 15 veces porque comienza con I = 1
y debido a que I++, se incrementará 1 en cada interaccion hasta que I sea igual que 15. */
