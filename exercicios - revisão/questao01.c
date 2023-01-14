#include <stdio.h>
#include <stdlib.h>

int main(){
    float metros, decimetros, centimetros, milimetros;
    printf("Digite o valor em metros: \n");
    scanf("%f", &metros);
    decimetros = metros * 10;
    centimetros = metros * 100;
    milimetros = metros * 1000;
    printf("Decimetros = %.2f \n", decimetros);
    printf("Centimetros = %.2f \n", centimetros);
    printf("Milimetros = %.2f \n", milimetros);

    return 0;
}