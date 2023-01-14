#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10], maior, menor, i, j;

    printf("Digite 10 números: ");
    for (i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }

    maior = vet[0];
    menor = vet[0];

    for (i = 1; i <= 10; i++){
        if(maior < vet[i]){
            maior = vet[i];
        }
        else{
            if(menor > vet[i]){
                menor = vet[i];
            }
        }
    }

    printf("MAIOR = %d \n", maior);
    printf("MENOR = %d \n", menor);

    return 0;
}