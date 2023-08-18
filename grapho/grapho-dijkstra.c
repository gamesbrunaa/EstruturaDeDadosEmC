#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4         // Número de discos
#define NUM_PEGS 3  // Número de pinos
#define NUM_CONFIGURACOES 81

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

void dijkstra(Vertice grapho[], int start, int end) {
    int distancia[NUM_CONFIGURACOES];
    int visitado[NUM_CONFIGURACOES];
    int pais[NUM_CONFIGURACOES];
    int i, count, v;
    
    for (i = 0; i < NUM_CONFIGURACOES; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = 0;
        pais[i] = -1;
    }
    
    distancia[start] = 0;
    
    for (count = 0; count < NUM_CONFIGURACOES - 1; count++) {
        int u = -1;
        for (i = 0; i < NUM_CONFIGURACOES; i++) {
            if (!visitado[i] && (u == -1 || distancia[i] < distancia[u])) {
                u = i;
            }
        }
        
        visitado[u] = 1;
        
        for (v = 0; v < NUM_CONFIGURACOES; v++) {
            if (!visitado[v] && arestasAdjacentes(grapho[u], grapho[v]) && distancia[u] + 1 < distancia[v]) {
                distancia[v] = distancia[u] + 1;
                pais[v] = u;
            }
        }
    }
    
    printf("Caminho minimo entre as configurações %d e %d:\n", start, end);
    printf("%d ", end);
    v = pais[end];
    while (v != start) {
        printf("%d ", v);
        v = pais[v];
    }
    printf("%d\n", start);
}

int main() {
    int i, j;

    Vertice grapho[NUM_CONFIGURACOES];
    for (i = 0; i < NUM_CONFIGURACOES; i++) {
        int num = i;
        for (j = 0; j < N; j++) {
            grapho[i].localizacao[j] = num % NUM_PEGS + 1;
            num /= NUM_PEGS;
        }
    }

    int start = 0;
    int end = 80;

    dijkstra(grapho, start, end);

    return 0;
}
