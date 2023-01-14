#include <stdio.h>
#include <stdlib.h>

int main (){
    int i;
    float vet[5], soma = 0, media;

    printf("Digite as notas dos alunos: ");
    for (i = 0; i < 5; i++){
        scanf("%f", &vet[i]);
        soma = soma + vet[i];
    }

    media = soma / 5;
    printf("MEDIA = %.1f", media);

    return 0;
}