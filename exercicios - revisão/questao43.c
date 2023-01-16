#include <stdio.h>
#include <stdlib.h>

int preencher(int tamanho){
    int *vet, i;
    vet = (int *) malloc(tamanho * sizeof(int));

    for(i = 0; i < tamanho; i++){
        vet[i] = rand() % 100;
    }

    return vet;
}

int main(){
    int n, *result, i;
    
    printf("Digite o valor n: \n");
    scanf("%d", &n);

    result = preencher(n);

    for(i = 0; i < n; i++){
        printf("%d \n", result[i]);
    }

    free(result);

    return 0;
}