// Implementar una pila (stack) usando una lista enlazada, con funciones push, pop y mostrar.

#include <stdio.h>
#include <stdlib.h>

// Definición del nodo para la pila.
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nodo.
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

// Push: insertar al inicio (tope de la pila).
void push(Nodo** tope, int valor) {
    Nodo* nuevo = crearNodo(valor);
    nuevo->siguiente = *tope;
    *tope = nuevo;
    printf("Elemento %d apilado.\n", valor);
}

// Pop: eliminar el primer nodo (tope de la pila).
int pop(Nodo** tope) {
    if (*tope == NULL) {
        printf("La pila está vacía.\n");
        return -1;
    }
    Nodo* temp = *tope;
    int valor = temp->dato;
    *tope = temp->siguiente;
    free(temp);
    printf("Elemento %d desapilado.\n", valor);
    return valor;
}

// Mostrar la pila.
void mostrarPila(Nodo* tope) {
    Nodo* actual = tope;
    printf("Pila (tope -> base): ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Liberar memoria.
void liberarPila(Nodo* tope) {
    while (tope != NULL) {
        Nodo* temp = tope;
        tope = tope->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* pila = NULL;
    int opcion, valor;

    do {
        printf("\nPila con lista enlazada\n");
        printf("1. Push (apilar).\n");
        printf("2. Pop (desapilar).\n");
        printf("3. Mostrar pila.\n");
        printf("4. Salir.\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%d", &valor);
                push(&pila, valor);
                break;
            case 2:
                pop(&pila);
                break;
            case 3:
                mostrarPila(pila);
                break;
            case 4:
                liberarPila(pila);
                printf("Memoria liberada. Fin del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}

