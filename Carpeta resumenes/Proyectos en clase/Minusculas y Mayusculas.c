#include <stdio.h>

int main()
{
    char Oracion[50];
    int i, mayusculas = 0, minusculas = 0;

    printf("Ingresa una oracion: ");
    scanf("%s", Oracion);

    for (i = 0; Oracion[i] != '\0'; i++)
    {
        if (Oracion[i] >= 65 && Oracion[i] <= 90)
        {
            mayusculas++;
        }
        else if (Oracion[i] >= 97 && Oracion[i] <= 122)
        {
            minusculas++;
        }
    }
    printf("Mayusculas: %d\n", mayusculas);
    printf("Minusculas: %d\n", minusculas);

    return 0;
}
