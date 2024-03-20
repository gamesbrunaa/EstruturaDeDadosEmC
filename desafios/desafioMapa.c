#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 20
#define qtd_quadrados 10
#define tam_quadrado 3

// Estrutura para representar uma posição
typedef struct {
    int x;
    int y;
} Posicao;

void inicializarMatriz(int matriz[tam][tam]){
    int i, j;

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            matriz[i][j] = 3;
        }
    }
}

void imprimirMatriz(int matriz[tam][tam]){
    int i, j;

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void gerarQuadrados(int matriz[tam][tam], int numQuadrados) {
    int k, i, j;
    for (k = 0; k < numQuadrados; k++) {
        int x = rand() % (tam - tam_quadrado + 1); // Posição x aleatória para o canto superior esquerdo
        int y = rand() % (tam - tam_quadrado + 1); // Posição y aleatória para o canto superior esquerdo

        // Preenche as células correspondentes ao quadrado 3x3
        for (i = x; i < x + tam_quadrado; i++) {
            for (j = y; j < y + tam_quadrado; j++) {
                matriz[i][j] = 0; // Marca a célula como ocupada
            }
        }
    }
}

// Função para encontrar os vértices dos quatro cantos de cada quadrado
void encontrarVerticesCantos(int matriz[tam][tam], Posicao verticesCantos[], int numQuadrados) {
    int k = 0;
    int i, j;

    for (i = 0; i < tam - tam_quadrado + 1; i++) {
        for (j = 0; j < tam - tam_quadrado + 1; j++) {
            if (matriz[i][j] == 0) {
                verticesCantos[k].x = i;
                verticesCantos[k].y = j;
                k++;
                verticesCantos[k].x = i;
                verticesCantos[k].y = j + tam_quadrado - 1;
                k++;
                verticesCantos[k].x = i + tam_quadrado - 1;
                verticesCantos[k].y = j;
                k++;
                verticesCantos[k].x = i + tam_quadrado - 1;
                verticesCantos[k].y = j + tam_quadrado - 1;
                k++;
            }
        }
    }
}

// Função para imprimir os vértices dos quatro cantos de cada quadrado
void imprimirVerticesCantos(Posicao verticesCantos[], int numVerticesCantos) {
    int i;
    printf("Vértices dos quatro cantos de cada quadrado:\n");
    for (i = 0; i < numVerticesCantos; i++) {
        printf("(%d, %d)\n", verticesCantos[i].x, verticesCantos[i].y);
    }
}

int main(){
    srand(time(NULL));

    int matriz[tam][tam];
    inicializarMatriz(matriz);
    gerarQuadrados(matriz, qtd_quadrados);
    imprimirMatriz(matriz);

    Posicao verticesCantos[qtd_quadrados * 4]; // Um quadrado tem 4 vértices
    encontrarVerticesCantos(matriz, verticesCantos, qtd_quadrados * 4);

    // Imprimir os vértices dos quatro cantos de cada quadrado
    imprimirVerticesCantos(verticesCantos, qtd_quadrados * 4);

    return 0;
}
