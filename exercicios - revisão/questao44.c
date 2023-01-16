#include <stdio.h>
#include <stdlib.h>

int criar(int tamanho){
    int *v;

    v = (int *) malloc(tamanho * sizeof(int));

    return v;
}

void imprimir(int *vet, int tamanho){
    int i;
    
    for(i = 0; i < tamanho; i++){
        printf("%d \n", vet[i]);
    }
}

void liberar(int *vet){
    free(vet);
}

int main(){
    int *vetor, n, i;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    vetor = criar(n);
    for(i = 0; i < n; i++){
        printf("Digite um numero inteiro: \n");
        scanf("%d", &vetor[i]);
    }

    imprimir(vetor, n);
    liberar(vetor);

    return 0;
}