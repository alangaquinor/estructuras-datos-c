// Crear un programa que permita agregar alumnos dinámicamente (usando malloc) hasta que el usuario decida parar, y luego mostrar todos los registros.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 50

// Definición de la estructura alumno.
typedef struct {
    char nombre[STR_LEN];
    int edad;
    float promedio;
} Alumno;

int main() {
    Alumno* alumnos = NULL;  // Puntero dinámico.
    int cantidad = 0;
    char opcion;

    do {
        // Reservar más memoria para un nuevo alumno.
        Alumno* temp = realloc(alumnos, (cantidad + 1) * sizeof(Alumno));
        if (temp == NULL) {
            printf("Error al asignar memoria.\n");
            free(alumnos);  // Liberar memoria previamente asignada antes de salir.
            exit(1);
        }
        alumnos = temp;  // Si realloc tiene éxito, actualizamos el puntero.

        // Ingresar datos del nuevo alumno.
        printf("\nIngrese datos del alumno %d:\n", cantidad + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", alumnos[cantidad].nombre);

        printf("Edad: ");
        scanf("%d", &alumnos[cantidad].edad);

        printf("Promedio: ");
        scanf("%f", &alumnos[cantidad].promedio);

        cantidad++;

        // Preguntar si desea continuar.
        printf("¿Desea ingresar otro alumno? (s/n): ");
        scanf(" %c", &opcion);  // Espacio antes de %c para evitar problemas con el salto de línea.

    } while (opcion == 's' || opcion == 'S');

    // Mostrar lista de alumnos.
    printf("\nLista de alumnos registrados:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Edad: %d | Promedio: %.2f\n",
               i + 1,
               alumnos[i].nombre,
               alumnos[i].edad,
               alumnos[i].promedio);
    }

    // Liberar memoria.
    free(alumnos);

    return 0;
}

