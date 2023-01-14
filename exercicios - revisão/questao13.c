#include <stdio.h>
#include <stdlib.h>

int enesima(int x, int n){
    int i, resultado = 1;
    for(i = 1; i <= n; i++){
        resultado *= x;
    }

    return resultado;
}

int main(){
    int numero1, numero2, result;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    result = enesima(numero1, numero2);
    printf("f(%d, %d) = %d", numero1, numero2, result);

    return 0;
}