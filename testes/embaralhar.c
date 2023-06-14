#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para embaralhar um array de inteiros
void embaralhar(int array[], int tamanho) {
    int i;
    srand(time(NULL)); // Inicializa a semente aleatória

    // Percorre o array do último elemento até o segundo
    for (i= tamanho - 1; i > 0; i--) {
        // Gera um índice aleatório entre 0 e i (inclusive)
        int j = rand() % (i + 1);

        // Troca os elementos nas posições i e j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int numeros[100];
    int i;

    // Preenche o array com os números de 1 a 100
    for (i = 0; i < 100; i++) {
        numeros[i] = i + 1;
    }

    // Embaralha o array
    embaralhar(numeros, 100);

    // Imprime o array embaralhado
    for (i = 0; i < 100; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}