#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    int valor = 10;
    int *ptr2;

    *ptr = valor;
    *ptr2 = &valor;
    printf("O valor é %d \n", *ptr);
    printf("O valor é %d \n", ptr);
    printf("O valor é %d \n", ptr2);
    printf("O valor é %d \n", *ptr2);
}