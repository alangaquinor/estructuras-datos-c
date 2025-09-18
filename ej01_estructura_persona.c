// Definir una estructura persona con nombre, edad y altura. Escribir un programa que cargue 5 personas y las muestre en pantalla.

#include <stdio.h>
#include <string.h>

#define MAX 5
#define STR_LEN 50

typedef struct {
    char nombre[STR_LEN];
    int edad;
    float altura;
} Persona;

int main() {
    Persona personas[MAX];
    int i;

    printf("Registro de %d personas\n", MAX);

    for (i = 0; i < MAX; i++) {
        printf("\nPersona %d\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", personas[i].nombre);
        printf("Edad: ");
        scanf("%d", &personas[i].edad);
        printf("Altura (en metros): ");
        scanf("%f", &personas[i].altura);
    }

    printf("\nLista de personas registradas\n");
    for (i = 0; i < MAX; i++) {
        printf("Persona %d: %s | Edad: %d | Altura: %.2f m\n",
               i + 1,
               personas[i].nombre,
               personas[i].edad,
               personas[i].altura);
    }

    return 0;
}

