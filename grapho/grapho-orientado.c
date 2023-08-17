#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#define N 4  // Número de vértices (tamanho do grafo)
#define INF 1.0  // Valor infinito para distâncias inalcançáveis

typedef struct {
    float confiabilidade;
} Aresta;

typedef struct {
    int num_vertices;
    Aresta arestas[N][N];
} Grafo;

typedef struct {
    float dist[N];
    int anterior[N];
} ResultadoDijkstra;

int arestasAdjacentes(Grafo *grafo, int u, int v) {
    return grafo->arestas[u][v].confiabilidade > 0.0;
}

ResultadoDijkstra dijkstra(Grafo *grafo, int origem) {
    ResultadoDijkstra resultado;
    int i, v, u;

    for (i = 0; i < grafo->num_vertices; i++) {
        resultado.dist[i] = -INFINITY;  // Inicializa com valor negativo
        resultado.anterior[i] = -1;
    }

    resultado.dist[origem] = 1.0;

    for (i = 0; i < grafo->num_vertices - 1; i++) {
        for (v = 0; v < grafo->num_vertices; v++) {
            for (u = 0; u < grafo->num_vertices; u++) {
                if (arestasAdjacentes(grafo, u, v)) {
                    float nova_confiabilidade = resultado.dist[u] * grafo->arestas[u][v].confiabilidade;
                    if (nova_confiabilidade > resultado.dist[v]) {
                        resultado.dist[v] = nova_confiabilidade;
                        resultado.anterior[v] = u;
                    }
                }
            }
        }
    }

    return resultado;
}

void imprimirCaminho(ResultadoDijkstra resultado, int destino) {
    if (resultado.dist[destino] <= 0) {
        printf("Caminho nao encontrado.\n");
        return;
    }

    printf("Confiabilidade maxima: %f\n", resultado.dist[destino]);
    printf("Caminho: ");

    int caminho[N];
    int tamanhoCaminho = 0;

    int atual = destino;
    while (atual != -1) {
        caminho[tamanhoCaminho++] = atual;
        atual = resultado.anterior[atual];
    }

    int i;

    for (i = tamanhoCaminho - 1; i >= 0; i--) {
        printf("%d", caminho[i]);
        if (i > 0) {
            printf(" -> ");
        }
    }

    printf("\n");
}

int main() {
    Grafo grafo = {
        .num_vertices = N,
        .arestas = {
            { {0.0}, {0.7}, {0.8}, {0.0} },
            { {0.0}, {0.0}, {0.0}, {0.0} },
            { {0.0}, {0.0}, {0.0}, {0.9} },
            { {0.0}, {0.0}, {0.0}, {0.0} }
        }
    };

    int origem = 0;   // Vértice de origem
    int destino = 3;   // Vértice de destino

    ResultadoDijkstra resultado = dijkstra(&grafo, origem);
    imprimirCaminho(resultado, destino);

    return 0;
}
