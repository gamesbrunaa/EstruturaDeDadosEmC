#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    double vet[tamanho];

    printf("Digite os valores do vetor: ");
    for(i = 0; i < tamanho; i++){
        scanf("%lf", &vet[i]);
    }

    for(i = 0; i < tamanho; i++){
        printf("%lf ", vet[i]);
    }

    return 0;
}