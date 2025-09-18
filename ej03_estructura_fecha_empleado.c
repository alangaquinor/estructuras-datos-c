// Definir una estructura fecha (día, mes, año) y usarla dentro de una estructura empleado. Mostrar la lista de empleados con sus fechas de ingreso.

#include <stdio.h>

#define MAX 5
#define STR_LEN 50

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[STR_LEN];
    int id;
    Fecha ingreso;
} Empleado;

int main() {
    Empleado empleados[MAX];
    int i;

    printf("Registro de %d empleados\n", MAX);

    for (i = 0; i < MAX; i++) {
        printf("\nEmpleado %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &empleados[i].id);

        printf("Nombre: ");
        scanf(" %[^\n]", empleados[i].nombre);

        printf("Fecha de ingreso (dd mm aaaa): ");
        scanf("%d %d %d",
              &empleados[i].ingreso.dia,
              &empleados[i].ingreso.mes,
              &empleados[i].ingreso.anio);
    }

    printf("\nLista de empleados\n");
    for (i = 0; i < MAX; i++) {
        printf("ID: %d | Nombre: %s | Ingreso: %02d/%02d/%04d\n",
               empleados[i].id,
               empleados[i].nombre,
               empleados[i].ingreso.dia,
               empleados[i].ingreso.mes,
               empleados[i].ingreso.anio);
    }

    return 0;
}

