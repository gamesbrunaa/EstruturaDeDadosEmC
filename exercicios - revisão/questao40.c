#include <stdio.h>
#include <stdlib.h>

float * notas(){
    int i;
    float *nota = (float *) malloc(3 * sizeof(float));

    printf("Digite as 3 notas: ");
    for (i = 0; i < 3; i++){
        scanf("%f", &nota[i]);
    }

    return nota;
}

int main(){
    float *n;
    int i;
    n = notas();
    for (i = 0; i < 3; i++){
        printf("%f \n", n[i]);
    }

    return 0;
}