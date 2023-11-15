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

void realizarTirada(FILE *historialArchivo, int tipoJuego, int *numerosElegidos) {
    int numero1, numero2, numero3;
    time_t current_time;
    time(&current_time);

    switch (tipoJuego) {
    case 1: // Tirar 3 números aleatorios
        numero1 = generarNumeroAleatorio(0, 99);
        numero2 = generarNumeroAleatorio(0, 99);
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    case 2: // Jugar un número
        numero1 = numerosElegidos[0];
        numero2 = generarNumeroAleatorio(0, 99);
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    case 3: // Jugar un pale
        numero1 = numerosElegidos[0];
        numero2 = numerosElegidos[1];
        numero3 = generarNumeroAleatorio(0, 99);
        break;
    case 4: // Jugar una tripleta
        numero1 = numerosElegidos[0];
        numero2 = numerosElegidos[1];
        numero3 = numerosElegidos[2];
        break;
    default:
        printf("Opción de juego no válida.\n");
        return;
    }

    fprintf(historialArchivo, "Tirada: %d %d %d - Fecha y hora: %s", numero1, numero2, numero3, ctime(&current_time));

    // Imprimir en consola los resultados
    if (tipoJuego == 1) {
        printf("Tirada: %d %d %d\n", numero1, numero2, numero3);
    } else {
        printf("Tus números: %d %d %d - Números de la Lotería: %d %d %d\n", numerosElegidos[0], numerosElegidos[1], numerosElegidos[2], numero1, numero2, numero3);
    }
}

int main() {
    srand(time(NULL));

    char opcion;
    int numerosElegidos[3]; // Agregado: arreglo para almacenar los números elegidos

    FILE *historialArchivo = fopen("historial.txt", "a+");

    if (historialArchivo == NULL) {
        printf("Aun no hay jugadas para mostrar en LoteWelnny, sea el primero en jugar acá, su banca preferida.\n");
        return 1;
    }

    do {
        printf("LoteWelnny\n");
        printf("0- Salir\n");
        printf("1- Tirar\n");
        printf("2. Historial\n");
        printf("3. Jugar 1 numero\n");
        printf("4. Jugar pale\n");
        printf("5. Jugar tripleta\n");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '0':
                printf("Saliendo del programa. Cerrando el archivo...\n");
                fclose(historialArchivo);
                break;
            case '1':
                realizarTirada(historialArchivo, 1, numerosElegidos); // Tipo de juego 1: Tirar 3 números aleatorios
                break;
            case '2':
                mostrarHistorial(historialArchivo);
                break;
            case '3':
                printf("Ingrese el número a jugar: ");
                scanf("%d", &numerosElegidos[0]);
                realizarTirada(historialArchivo, 2, numerosElegidos); // Tipo de juego 2: Jugar un número
                break;
            case '4':
                printf("Ingrese el primer número del pale: ");
                scanf("%d", &numerosElegidos[0]);
                printf("Ingrese el segundo número del pale: ");
                scanf("%d", &numerosElegidos[1]);
                realizarTirada(historialArchivo, 3, numerosElegidos); // Tipo de juego 3: Jugar un pale
                break;
            case '5':
                printf("Ingrese el primer número de la tripleta: ");
                scanf("%d", &numerosElegidos[0]);
                printf("Ingrese el segundo número de la tripleta: ");
                scanf("%d", &numerosElegidos[1]);
                printf("Ingrese el tercer número de la tripleta: ");
                scanf("%d", &numerosElegidos[2]);
                realizarTirada(historialArchivo, 4, numerosElegidos); // Tipo de juego 4: Jugar una tripleta
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }
    } while (opcion != '0');

    return 0;
}
