#include <stdio.h>

/* Cuenta n�meros
El programa, al recibir datos como un arreglo unidimesional de tipo entero y un n�meros entero, determina cu�ntas veces se encuentra el n�mero en el arreglo. */

void main(void)
{
    int I, NUM, CUE = 0;
    int ARRE[15];                                  /* Declaraci�n del arreglo*/
    for (I=0; I<15; I++)
    {
       printf("Ingrese el elemento %d del arreglo:", I+1);
       scanf("%d", &ARRE[I]);                     /*Lecutra asignaci�n- del arreglo. */
    }
    printf("\n\nIgrese el n�mero que se va a buscar en el arreglo:");
    scanf("%d", &NUM);
     for (I=0; I<15; I++)
        if (ARRE[I] == NUM)                 /*Comparaci�n del n�mero con los elementos del arreglo.*/

              CUE++;
     printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);
 }
