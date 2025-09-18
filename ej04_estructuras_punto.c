// Crear una función que compare si dos estructuras punto(x, y) son iguales.

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Punto;

int compararPuntos(Punto p1, Punto p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

int main() {
    Punto p1, p2;

    printf("Ingrese las coordenadas del primer punto (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Ingrese las coordenadas del segundo punto (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    if (compararPuntos(p1, p2)) {
        printf("Los puntos son iguales.\n");
    } else {
        printf("Los puntos son diferentes.\n");
    }

    return 0;
}

