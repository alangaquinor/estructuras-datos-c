// Implementar una lista doblemente enlazada de caracteres con inserción al final y recorrido en ambos sentidos.

#include <stdio.h>
#include <stdlib.h>

// Definición del nodo para lista doblemente enlazada.
typedef struct Nodo {
    char dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

// Crear un nuevo nodo.
Nodo* crearNodo(char valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Insertar al final.
void insertarFinal(Nodo** cabeza, char valor) {
    Nodo* nuevo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

// Mostrar lista de inicio a fin.
void mostrarAdelante(Nodo* cabeza) {
    Nodo* actual = cabeza;
    printf("Lista adelante: ");
    while (actual != NULL) {
        printf("%c <-> ", actual->dato);
        if (actual->siguiente == NULL) break; // Guardar el último para recorrer atrás.
        actual = actual->siguiente;
    }
    printf("NULL\n");

    // Mostrar hacia atrás desde el último nodo.
    printf("Lista atrás: ");
    while (actual != NULL) {
        printf("%c <-> ", actual->dato);
        actual = actual->anterior;
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
    int opcion;
    char valor;

    do {
        printf("\nLista doblemente enlazada\n");
        printf("1. Insertar al final.\n");
        printf("2. Mostrar lista adelante y atrás.\n");
        printf("3. Salir.\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un caracter: ");
                scanf(" %c", &valor); // Espacio antes para ignorar '\n'.
                insertarFinal(&lista, valor);
                break;
            case 2:
                mostrarAdelante(lista);
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

