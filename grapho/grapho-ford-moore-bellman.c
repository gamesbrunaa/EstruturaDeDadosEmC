#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 4  // Número de discos
#define NUM_PEGS 3  // Número de pinos

typedef struct {
    int localizacao[N];
} Vertice;

int arestasAdjacentes(Vertice v1, Vertice v2) {
    int i;
    int diferencaCont = 0;
    for (i = 0; i < N; i++) {
        if (v1.localizacao[i] != v2.localizacao[i]) {
            diferencaCont++;
            if (diferencaCont > 1) {
                return 0;
            }
        }
    }
    return diferencaCont == 1;
}

void FordMooreBellman(Vertice grapho[], int start, int end) {
    int distancia[1 << N];
    int pais[1 << N];
    int i, count, v, u;
    
    for (i = 0; i < (1 << N); i++) {
        distancia[i] = INT_MAX;
        pais[i] = -1;
    }
    
    distancia[start] = 0;
    
    for (count = 0; count < (1 << N) - 1; count++) {
        for (u = 0; u < (1 << N); u++) {
            for (v = 0; v < (1 << N); v++) {
                if (arestasAdjacentes(grapho[u], grapho[v]) && distancia[u] + 1 < distancia[v]) {
                    distancia[v] = distancia[u] + 1;
                    pais[v] = u;
                }
            }
        }
    }
    
    int caminho[1 << N];
    int tamanhoCaminho = 0;
    int rastrear = end;
    while (rastrear != -1) {
        caminho[tamanhoCaminho++] = rastrear;
        rastrear = pais[rastrear];
    }
    
    printf("Caminho minimo:\n");
    for (i = tamanhoCaminho - 1; i >= 0; i--) {
        printf("%d ", caminho[i]);
    }
    printf("\n");
}

int main() {
    clock_t start_time, end_time;
    int i, j;

    Vertice grapho[1 << N];
    for (i = 0; i < (1 << N); i++) {
        int num = i;
        for (j = 0; j < N; j++) {
            grapho[i].localizacao[j] = num % NUM_PEGS + 1;
            num /= NUM_PEGS;
        }
    }

    int start = 0;
    int end = (1 << N) - 1;

    start_time = clock();
    FordMooreBellman(grapho, start, end);
    end_time = clock();

    double tempo = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %lf segundos\n", tempo);

    return 0;
}
