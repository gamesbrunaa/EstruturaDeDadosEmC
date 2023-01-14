#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10], i, j, aux=0;

    printf("Digite 1 numeros: ");
    for (i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if (vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    for (i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }

    return 0;
    
}