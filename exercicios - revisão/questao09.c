#include <stdio.h>
#include <stdlib.h>

int main(){
    int valor1, valor2, final;
    char operador;

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);
    printf("Digite o operador: ");
    scanf("%s", &operador);
    printf("Digite o sgundo valor: ");
    scanf("%d", &valor2);

    if(operador == '+'){
        final = valor1 + valor2;
    }else if (operador == '-'){
        final = valor1 - valor2;
    }else if (operador == '*'){
        final = valor1 * valor2;
    }else if (operador == '/'){
        final = valor1 / valor2;
    }else{
        printf("Operador Invalido!!!");
    }

    printf("%d %c %d = %d \n", valor1, operador, valor2, final);
    
    return 0;
}