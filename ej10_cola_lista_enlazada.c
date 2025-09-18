// Implementar una cola (queue) usando una lista enlazada, con funciones enqueue, dequeue y mostrar.

#include <stdio.h>
#include <stdlib.h>

// Definición de nodo para la cola.
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Definición de la cola con punteros a frente y final.
typedef struct {
    Nodo* frente;
    Nodo* final;
} Cola;

// Crear cola vacía.
void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

// Crear un nuevo nodo.
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

// Enqueue: insertar al final.
void enqueue(Cola* cola, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (cola->final == NULL) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    printf("Elemento %d encolado.\n", valor);
}

// Dequeue: eliminar del frente.
int dequeue(Cola* cola) {
    if (cola->frente == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    Nodo* temp = cola->frente;
    int valor = temp->dato;
    cola->frente = temp->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL; // Si quedó vacía.
    }
    free(temp);
    printf("Elemento %d desencolado.\n", valor);
    return valor;
}

// Mostrar cola.
void mostrarCola(Cola* cola) {
    Nodo* actual = cola->frente;
    printf("Cola (frente -> final): ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Liberar memoria.
void liberarCola(Cola* cola) {
    while (cola->frente != NULL) {
        Nodo* temp = cola->frente;
        cola->frente = cola->frente->siguiente;
        free(temp);
    }
    cola->final = NULL;
}

int main() {
    Cola cola;
    inicializarCola(&cola);

    int opcion, valor;

    do {
        printf("\nCola con lista enlazada\n");
        printf("1. Enqueue (encolar).\n");
        printf("2. Dequeue (desencolar).\n");
        printf("3. Mostrar cola.\n");
        printf("4. Salir.\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%d", &valor);
                enqueue(&cola, valor);
                break;
            case 2:
                dequeue(&cola);
                break;
            case 3:
                mostrarCola(&cola);
                break;
            case 4:
                liberarCola(&cola);
                printf("Memoria liberada. Fin del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}

