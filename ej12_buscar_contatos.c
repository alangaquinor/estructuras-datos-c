// Crear un programa que guarde contactos (nombre, teléfono, email) en una lista enlazada y permita buscar por nombre.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 50

// Definición del nodo contacto.
typedef struct Contacto {
    char nombre[STR_LEN];
    char telefono[STR_LEN];
    char email[STR_LEN];
    struct Contacto* siguiente;
} Contacto;

// Crear un nuevo contacto.
Contacto* crearContacto(char nombre[], char telefono[], char email[]) {
    Contacto* nuevo = (Contacto*)malloc(sizeof(Contacto));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->telefono, telefono);
    strcpy(nuevo->email, email);
    nuevo->siguiente = NULL;
    return nuevo;
}

// Insertar contacto al inicio de la lista.
void insertarContacto(Contacto** cabeza, char nombre[], char telefono[], char email[]) {
    Contacto* nuevo = crearContacto(nombre, telefono, email);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    printf("Contacto agregado: %s\n", nombre);
}

// Mostrar todos los contactos.
void mostrarContactos(Contacto* cabeza) {
    if (cabeza == NULL) {
        printf("No hay contactos registrados.\n");
        return;
    }
    printf("\nLista de contactos\n");
    Contacto* actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s | Tel: %s | Email: %s\n",
               actual->nombre, actual->telefono, actual->email);
        actual = actual->siguiente;
    }
}

// Buscar un contacto por nombre.
void buscarContacto(Contacto* cabeza, char nombre[]) {
    Contacto* actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Contacto encontrado:\n");
            printf("Nombre: %s | Tel: %s | Email: %s\n",
                   actual->nombre, actual->telefono, actual->email);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Contacto con nombre \"%s\" no encontrado.\n", nombre);
}

// Liberar memoria.
void liberarContactos(Contacto* cabeza) {
    while (cabeza != NULL) {
        Contacto* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Contacto* agenda = NULL;
    int opcion;
    char nombre[STR_LEN], telefono[STR_LEN], email[STR_LEN];

    do {
        printf("\nAgenda de contactos\n");
        printf("1. Agregar contacto.\n");
        printf("2. Mostrar contactos.\n");
        printf("3. Buscar contacto.\n");
        printf("4. Salir.\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Nombre: ");
                scanf(" %[^\n]", nombre);
                printf("Teléfono: ");
                scanf(" %[^\n]", telefono);
                printf("Email: ");
                scanf(" %[^\n]", email);
                insertarContacto(&agenda, nombre, telefono, email);
                break;
            case 2:
                mostrarContactos(agenda);
                break;
            case 3:
                printf("Ingrese el nombre a buscar: ");
                scanf(" %[^\n]", nombre);
                buscarContacto(agenda, nombre);
                break;
            case 4:
                liberarContactos(agenda);
                printf("Memoria liberada. Fin del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}

