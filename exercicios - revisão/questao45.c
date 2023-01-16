#include <stdio.h>
#include <stdlib.h>

int **criar(int m, int n){
    int **matriz, i;
    matriz = (int **) malloc(m * sizeof(int*));
    for(i = 0; i < m; i++){
        matriz[i] = (int *) malloc(n * sizeof(int));
    }

    return matriz;
}

int **preencher(int **m, int a, int b){
    int i, j;
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            m[i][j] = rand() % 100;
        }
    }

    return m;
}

void imprimir(int **m, int a, int b){
    int i, j;
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void liberar(int **m, int a){
    int i;
    for(i = 0; i < a; i++){
        free(m[i]);
    }

    free(m);
}

int main(){
    int m, n, i;

    printf("Digite a quantidade de linhas: \n");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas: \n");
    scanf("%d", &n);
    int **mat2;

    mat2 = criar(m, n);
    mat2 = preencher(mat2, m, n);
    imprimir(mat2, m, n);
    liberar(mat2, m);

    return 0;
}