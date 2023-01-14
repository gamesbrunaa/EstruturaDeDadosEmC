#include <stdio.h>
#include <stdlib.h>

int main(){
    double f, c;
    int f1, c1;

    printf("Digite o valor em Fahrenheit: ");
    scanf("%lf", &f);
    printf("Digite o valor em Fahrenheit: ");
    scanf("%d", &f1);

    c = (f - 32.0) * (5.0 / 9.0);
    c1 = (f1 - 32) * 5 / 9;

    printf("C = %lf \n", c);
    printf("C = %d \n", c1);

    return 0;
}