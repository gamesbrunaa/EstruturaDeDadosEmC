#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000 // Número máximo de vértices
#define INF 1e9           // Valor infinito para representar distâncias inalcançáveis

typedef struct {
    int destino;
    double confiabilidade;
} Aresta;

typedef struct {
    Aresta arestas[MAX_VERTICES];
    int numArestas;
} Vertice;

typedef struct {
    Vertice vertices[MAX_VERTICES];
    int numVertices;
} Grafo;

void inicializarGrafo(Grafo *grafo, int numVertices) {
    int i;

    grafo->numVertices = numVertices;
    for (i = 0; i < numVertices; i++) {
        grafo->vertices[i].numArestas = 0;
    }
}

void adicionarAresta(Grafo *grafo, int origem, int destino, double confiabilidade) {
    Aresta aresta = {destino, confiabilidade};
    grafo->vertices[origem].arestas[grafo->vertices[origem].numArestas] = aresta;
    grafo->vertices[origem].numArestas++;
}

void dijkstra(Grafo *grafo, int origem, int destino) {
    double dist[MAX_VERTICES];
    int visitado[MAX_VERTICES];
    int i, count;

    for (i = 0; i < grafo->numVertices; i++) {
        dist[i] = 0.0; // Inicializa as distâncias com 0 (conexões não visitadas)
        visitado[i] = 0;
    }
    dist[origem] = 1.0; // A confiabilidade da origem é 1 (100%)

    for (count = 0; count < grafo->numVertices - 1; count++) {
        int u = -1;
        for (i = 0; i < grafo->numVertices; i++) {
            if (!visitado[i] && (u == -1 || dist[i] > dist[u])) {
                u = i;
            }
        }

        visitado[u] = 1;

        for (i = 0; i < grafo->vertices[u].numArestas; i++) {
            Aresta aresta = grafo->vertices[u].arestas[i];
            int v = aresta.destino;
            double confiabilidade = aresta.confiabilidade;
            if (dist[u] * confiabilidade > dist[v]) {
                dist[v] = dist[u] * confiabilidade;
            }
        }
    }

    printf("A confiabilidade máxima entre %d e %d é %.6lf\n", origem, destino, dist[destino]);
}

int main() {
    int numVertices, numArestas;
    int origem, destino, i;
    double confiabilidade;

    printf("Digite o numero de vertices: ");
    scanf("%d", &numVertices);

    printf("Digite o numero de arestas: ");
    scanf("%d", &numArestas);

    Grafo grafo;
    inicializarGrafo(&grafo, numVertices);

    for (i = 0; i < numArestas; i++) {
        int u, v;
        scanf("%d %d %lf", &u, &v, &confiabilidade);
        adicionarAresta(&grafo, u, v, confiabilidade);
    }

    printf("Digite a origem: ");
    scanf("%d", &origem);

    printf("Digite o destino: ");
    scanf("%d", &destino);

    dijkstra(&grafo, origem, destino);

    return 0;
}
