// Definir estructura alumno con nombre y tres notas. Calcular el promedio de cada alumno e indicar quién tiene el mejor.

#include <stdio.h>
#include <string.h>

#define MAX 5
#define STR_LEN 50

typedef struct {
    char nombre[STR_LEN];
    float notas[3];
    float promedio;
} Alumno;

int main() {
    Alumno alumnos[MAX];
    int i, j;
    int mejorIndice = 0;

    printf("Registro de %d alumnos\n", MAX);

    for (i = 0; i < MAX; i++) {
        printf("\nAlumno %d\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", alumnos[i].nombre);

        alumnos[i].promedio = 0;
        for (j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alumnos[i].notas[j]);
            alumnos[i].promedio += alumnos[i].notas[j];
        }
        alumnos[i].promedio /= 3.0;

        if (alumnos[i].promedio > alumnos[mejorIndice].promedio) {
            mejorIndice = i;
        }
    }
    
    printf("\nLista de alumnos y promedios\n");
    for (i = 0; i < MAX; i++) {
        printf("%s | Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }

    printf("\nEl alumno con mejor promedio es: %s (%.2f)\n",
           alumnos[mejorIndice].nombre,
           alumnos[mejorIndice].promedio);

    return 0;
}

