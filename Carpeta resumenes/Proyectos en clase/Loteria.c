#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORIAL 1000

struct Loteria
{
    int numeros[3];
    time_t fecha_hora;
};

struct Loteria historial[MAX_HISTORIAL];
int intento_actual = 0;

void generarNumeros(int numeros[3]) {
    for (int i = 0; i < 3; ++i) {
        numeros[i] = rand() % 100 + 1;
    }
}

void guardarEnHistorial(int numeros[3]) {
    if (intento_actual < MAX_HISTORIAL) {
        struct Loteria nuevo_registro;
        for (int i = 0; i < 3; ++i) {
            nuevo_registro.numeros[i] = numeros[i];
        }
        nuevo_registro.fecha_hora = time(NULL);
        historial[intento_actual] = nuevo_registro;
        intento_actual++;
    } else {
        printf("¡Historial lleno! No se pueden agregar más registros.\n");
    }
}

void imprimirHistorial() {
    printf("\nHistorial de números:\n");
    for (int i = 0; i < intento_actual; ++i) {
        printf("Intento %d - Fecha y hora: %s\n",
               i + 1, ctime(&historial[i].fecha_hora)
        );
        printf("Estos son los números ganadores en LoteWelnny: ");
        for (int j = 0; j < 3; ++j) {
            printf("%d ", historial[i].numeros[j]);
        }
        printf("\n\n");
    }
}

void main(void)

{
    srand(time(NULL));

    int opcion;

    while (1)
    {
        printf("\n--- LoteWelnny ---\n");
        printf("0-Salir\n");
        printf("1-Tirar\n");
        printf("2-historial\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                {
                    int numeros[3];
                    generarNumeros(numeros);
                    guardarEnHistorial(numeros);

                    printf("\n¡Felicidades! Ha participado en la lotería.\n");
                    printf("Estos son los números ganadores en LoteWelnny: ");
                    for (int j = 0; j < 3; ++j) {
                        printf("%d ", numeros[j]);
                    }
                    printf("\n\n");
                }
                break;

            case 2:
                imprimirHistorial();
                break;
            case 3:
                printf("Te esperamos pronto en LoteWelnny\n");
                return 0;

            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    }

}
