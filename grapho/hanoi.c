#include <stdio.h>

void hanoi(int n, int origem, int destino, int auxiliar) {
    if (n == 0) {
        printf("Mova o disco 1 da torre %d para a torre %d\n", origem, destino);
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mova o disco %d da torre %d para a torre %d\n", n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n = 3;  // Número de discos
    hanoi(n, 1, 3, 2); // Chamada da função com torres de origem, destino e auxiliar

    return 0;
}
