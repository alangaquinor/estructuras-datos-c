// Implementar una lista enlazada de enteros con funciones para insertar al inicio y mostrar los elementos.

#include <stdio.h>
#include <stdlib.h>

// Definición del nodo.
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nuevo nodo.
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Insertar al inicio.
void insertarInicio(Nodo** cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Mostrar la lista.
void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Liberar memoria.
void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* lista = NULL;
    int opcion, valor;

    do {
        printf("\nLista enlazada simple\n");
        printf("1. Insertar al inicio.\n");
        printf("2. Mostrar lista.\n");
        printf("3. Salir.\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%d", &valor);
                insertarInicio(&lista, valor);
                break;
            case 2:
                mostrarLista(lista);
                break;
            case 3:
                liberarLista(lista);
                printf("Memoria liberada. Fin del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 3);

    return 0;
}

