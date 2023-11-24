#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *a, *b;

    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));

    *a = 5;
    *b = 10;

    printf("El valor de a es: %d", *a);
    printf("El valor de b es: %d\n", *b);

    printf("El valor de la suma entre a y b es: %d\n", (*a + *b));

    free(a);
    free(b);
    a = NULL;
    b = NULL;
}





