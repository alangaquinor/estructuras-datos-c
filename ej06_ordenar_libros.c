// Guardar 5 libros (título, autor, año). Ordenarlos por año de publicación y mostrarlos.

#include <stdio.h>
#include <string.h>

#define MAX 5
#define STR_LEN 100

// Definición de la estructura libro.
typedef struct {
    char titulo[STR_LEN];
    char autor[STR_LEN];
    int anio;
} Libro;

void ordenarPorAnio(Libro libros[], int n) {
    int i, j;
    Libro temp;
    // Método de burbuja.
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (libros[j].anio > libros[j + 1].anio) {
                temp = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = temp;
            }
        }
    }
}

int main() {
    Libro libros[MAX];
    int i;

    printf("Registro de %d libros\n", MAX);

    // Entrada de datos.
    for (i = 0; i < MAX; i++) {
        printf("\nLibro %d\n", i + 1);

        printf("Título: ");
        scanf(" %[^\n]", libros[i].titulo);

        printf("Autor: ");
        scanf(" %[^\n]", libros[i].autor);

        printf("Año de publicación: ");
        scanf("%d", &libros[i].anio);
    }

    // Ordenar los libros por año.
    ordenarPorAnio(libros, MAX);

    // Salida de datos.
    printf("\nLista de libros ordenados por año\n");
    for (i = 0; i < MAX; i++) {
        printf("%d | \"%s\" de %s\n",
               libros[i].anio,
               libros[i].titulo,
               libros[i].autor);
    }

    return 0;
}

