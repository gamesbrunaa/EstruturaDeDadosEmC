#include <stdio.h>
#include <stdlib.h>

float * operacao(float numero1, float numero2){
    float *vet = (float *) malloc(3 * sizeof(float));
    vet[0] = numero1 + numero2;
    vet[1] = numero1 - numero2;
    vet[2] = numero1 * numero2;

    return vet;
}

int main(){
    float n1, n2, *result;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    result = operacao(n1, n2);

    printf("SOMA = %.2f \n", result[0]);
    printf("DIFERENCA = %.2f \n", result[1]);
    printf("PRODUTO = %.2f \n", result[2]);

    return 0;
}