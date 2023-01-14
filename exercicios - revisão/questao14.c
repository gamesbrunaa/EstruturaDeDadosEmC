#include <stdio.h>
#include <stdlib.h>

int fatorial_recursivo(int num){
    int valorfat;
    if (num <= 1)
        return (1);
    else{
        valorfat = num * fatorial_recursivo(num - 1);
        return (valorfat);
    }
}

int fatorial(int num){
    int i;
    for (i = 1; num > 1; num = num - 1){
        i = i * num;
    }

    return i;
}

int main(){
    int numero, result1, result2;

    printf("Digite o numero: ");
    scanf("%d", &numero);

    result1 = fatorial_recursivo(numero);
    result2 = fatorial(numero);
    printf("Fatorial de %d é = %d \n", numero, result1);
    printf("Fatorial de %d é = %d \n", numero, result2);

    return 0;
}