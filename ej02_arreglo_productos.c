// Crear un arreglo de 10 productos con campos id, nombre y precio. Permitir al usuario ingresar los datos y luego imprimirlos.

#include <stdio.h>

#define MAX 10
#define STR_LEN 50

typedef struct {
    int id;
    char nombre[STR_LEN];
    float precio;
} Producto;

int main() {
    Producto productos[MAX];
    int i;

    printf("Registro de %d productos\n", MAX);

    for (i = 0; i < MAX; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &productos[i].id);

        printf("Nombre: ");
        scanf(" %[^\n]", productos[i].nombre);

        printf("Precio: ");
        scanf("%f", &productos[i].precio);
    }

    printf("\nLista de productos registrados\n");
    for (i = 0; i < MAX; i++) {
        printf("ID: %d | Nombre: %s | Precio: $%.2f\n",
               productos[i].id,
               productos[i].nombre,
               productos[i].precio);
    }

    return 0;
}

