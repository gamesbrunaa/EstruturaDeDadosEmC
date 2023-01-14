#include <stdio.h>
#include <stdlib.h>

int main(){
    float prod, infla, final;

    printf("Digite o valor do produto: ");
    scanf("%f", &prod);

    if (prod < 100){
        infla = prod * 0.10;
        final = prod + infla;
    }else if (prod >= 100){
        infla = prod * 0.20;
        final = prod + infla;
    }

    printf("O valor do produto final = %.2f", final);

    return 0;
}