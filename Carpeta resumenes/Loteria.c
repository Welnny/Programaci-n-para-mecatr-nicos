#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

void mostrarHistorial(FILE *historialArchivo) {
    rewind(historialArchivo);
    printf("Historial:\n");
    char linea[256];
    while (fgets(linea, sizeof(linea), historialArchivo)) {
        printf("%s", linea);
    }
}

int main() {
    srand(time(NULL));

    char opcion;
    int numero1, numero2, numero3;

    FILE *historialArchivo = fopen("historial.txt", "a+");

    if (historialArchivo == NULL) {
        printf("Aun no hay jugadas para mostrar en LoteWelnny, sea el primero en jugar aca, su banca preferida.\n");
        return 1;
    }

    do {
        printf("LoteWelnny\n");
        printf("0- Salir\n");
        printf("1- Tirar\n");
        printf("2. Historial\n");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '0':
                printf("Saliendo del programa. Cerrando el archivo...\n");
                fclose(historialArchivo);
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");

            case '1':
                numero1 = generarNumeroAleatorio(0, 99);
                numero2 = generarNumeroAleatorio(0, 99);
                numero3 = generarNumeroAleatorio(0, 99);
                time_t current_time;
                time(&current_time);

                fprintf(historialArchivo, "Tirada: %d %d %d - Fecha y hora: %s", numero1, numero2, numero3, ctime(&current_time));
                printf("Tirada: %d %d %d\n", numero1, numero2, numero3);
                break;
            case '2':
                mostrarHistorial(historialArchivo);
                break;
        }
    } while (opcion != '3');

    return 0;
}
