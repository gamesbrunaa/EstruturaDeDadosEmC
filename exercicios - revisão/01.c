#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    int valor = 10;
    int *ptr2;

    ptr2 = &valor;
    printf("1.O valor é %d \n", &ptr2);
    printf("2.O valor é %d \n", ptr2);
}
