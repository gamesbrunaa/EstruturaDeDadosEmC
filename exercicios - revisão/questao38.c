#include <stdio.h>
#include <stdlib.h>

float * razao(int a, int b){
    float *result = (float *) malloc(2 * sizeof(float));
    if(b == 0){
        result[0] = 0;
        result[1] = 0;
    } else{
        result[0] = 1;
        result[1] = a / b;
    }

    return result;
}

int main(){
    float n1, n2, *recebe;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    recebe = razao(n1, n2);
    if(recebe[0] == 0)
        printf("Operação não foi possivel!!");
    else{
        printf("Operação realizada! \n");
        printf("RAZAO = %.2f", recebe[1]);
    }

    return 0;
}